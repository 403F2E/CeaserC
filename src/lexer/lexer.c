
#include "../../headers/utils.h" // IWYU pragma: keep
#include "Tokenizer.h"
#include <stdlib.h>

// Create Token instance
Token createToken(int type, char *value) {
  Token token;
  token.type = type;
  token.value = (char *)malloc(sizeof(value));
  token.value = value;
  return token;
}

// Create Token List instance
TokenList *createTokenList() {
  TokenList *tokenList = (TokenList *)malloc(sizeof(TokenList));
  if (tokenList == NULL) {
    perror("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  tokenList->head = NULL;
  tokenList->tail = NULL;
  tokenList->prev = NULL;

  return tokenList;
}

// Add token to the end of the token list
void addTokenEnd(TokenList *tokenList, Token token) {
  if (tokenList->head == NULL) {
    tokenList->token = token;
  } else {
    tokenList->tail->tail = tokenList->head;
    tokenList->prev = tokenList->tail;
    tokenList->token = token;
  }
}

// function determine the whole number and parse it into a double
Token isNumber(char *cursor, FILE *file) {
  ungetc(*(cursor), file);

  Token token;
  token.type = INT;
  token.value = (char *)malloc(sizeof(char));
  token.value[0] = '\0';

  if (token.value == NULL) {
    free(token.value);
    token.value = NULL;
    perror("Memory allocation failed.\n");
    return token;
  }

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isdigit(*(cursor)) || *cursor != '.') {
      printf("%s\n", token.value);
      ungetc(*(cursor), file);
      return token;
    }

    char *tmp = (char *)realloc(token.value, (strlen(token.value) + 2));
    if (tmp == NULL) {
      free(token.value);
      token.value = NULL;
      return token;
    }

    token.value = tmp;

    size_t len = strlen(token.value);
    token.value[len] = *cursor;
    token.value[len + 1] = '\0';
  }

  return token;
}

// Function to read the whole token and determine whether it is a type or an
// identifier or a keyword
Token identifyAlpha(char *cursor, FILE *file) {
  ungetc(*(cursor), file);
  Token token;
  token.value = (char *)malloc(sizeof(char));
  token.value[0] = '\0';

  if (token.value == NULL) {
    free(token.value);
    token.value = NULL;
    perror("Memory allocation failed.\n");
    return token;
  }

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isdigit(*cursor)) {
      if (!strcmp(token.value, "int")) {
        token.type = INT;
        printf("%s TYPE Found!!\n", token.type ? "INT" : "");
      } else if (!strcmp(token.value, "float")) {
        token.type = FLOAT;
        printf("FLOAT TYPE Found!!\n");
      } else {
        token.type = IDENTIFIER;
        printf("IDENTIFIER Found!!\n");
      }
      free(token.value);
      token.value = NULL;
      ungetc(*(cursor), file);
      return token;
    }

    char *tmp = (char *)realloc(token.value, (strlen(token.value) + 2));
    if (tmp == NULL) {
      free(token.value);
      token.value = NULL;
      return token;
    }

    token.value = tmp;

    size_t len = strlen(token.value);
    token.value[len] = *cursor;
    token.value[len + 1] = '\0';
  }

  return token;
}

TokenList lexer(FILE *file) {
  char cursor;
  Token token;
  TokenList *tokenList = createTokenList();

  while ((cursor = fgetc(file)) != EOF) {
    if (cursor == ' ')
      continue;
    else if (cursor == '@') {
      printf("ALGO FOUND!!\n");
      char value = cursor + '\0';
      token = createToken(ALGO, &value);
    } else if (cursor == ':') {
      printf("COLONS Found!!\n");
      char value = cursor + '\0';
      token = createToken(COLON, &value);
    } else if (cursor == '=') {
      printf("AFFECT FOUND!!\n");
      char value = cursor + '\0';
      token = createToken(AFFECT, &value);
    } else if (cursor == ';') {
      printf("SEMICOLONS Found!!\n");
      char value = cursor + '\0';
      token = createToken(SEMI, &value);
    } else if (isalpha(cursor)) {
      token = identifyAlpha(&cursor, file);
    } else if (isdigit(cursor)) {
      printf("NUMBER found!!\n");
      token = isNumber(&cursor, file);
    }

    addTokenEnd(tokenList, token);
  }

  return *tokenList;
}
