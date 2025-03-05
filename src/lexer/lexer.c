
#include "../../headers/utils.h" // IWYU pragma: keep
#include "Tokenizer.h"
#include <stdlib.h>
#include <string.h>

// Create Token instance
Token createToken(int type, char *value) {
  Token token;
  token.type = type;

  token.value = (char *)malloc(sizeof(value));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed for the current token value.\n");
    exit(EXIT_FAILURE);
  }

  token.value = value;
  return token;
}

// Create Token List instance
TokenList *createTokenList() {
  TokenList *tokenList = (TokenList *)malloc(sizeof(TokenList));
  if (tokenList == NULL) {
    free(tokenList);
    perror("Memory allocation failed for the current tokens list.\n");
    exit(EXIT_FAILURE);
  }

  tokenList->tail = tokenList->prev = tokenList;

  return tokenList;
}

// Add token to the end of the token list
TokenList *addTokenEnd(TokenList *tokenList, Token token) {
  TokenList *newTokenNode = (TokenList *)malloc(sizeof(TokenList));
  if (newTokenNode == NULL) {
    free(newTokenNode);
    perror("Memory allocation failed for the new token node.\n");
    exit(EXIT_FAILURE);
  }

  newTokenNode->token = token;
  newTokenNode->prev = tokenList->prev;
  newTokenNode->tail = tokenList;
  tokenList->prev->tail = newTokenNode;
  tokenList->prev = newTokenNode;

  return tokenList;
}

// function determine the whole number and parse it into a double
Token isNumber(char *cursor, FILE *file) {
  ungetc(*(cursor), file);

  Token token;
  token.type = INT;
  token.value = (char *)malloc(sizeof(char));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed for the current token value.\n");
    exit(EXIT_FAILURE);
  }
  token.value[0] = '\0';

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isdigit(*cursor) && *cursor != '.') {
      printf("%s\n", token.value);
      ungetc(*(cursor), file);
      return token;
    }

    char *tmp = (char *)realloc(token.value, (strlen(token.value) + 2));
    if (tmp == NULL) {
      free(token.value);
      token.value = NULL;
      perror("Memory reallocation failed for the current token value.\n");
      exit(EXIT_FAILURE);
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
Token identifyAlphanum(char *cursor, FILE *file) {
  ungetc(*(cursor), file);
  Token token;
  token.value = (char *)malloc(sizeof(char));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed.\n");
    return token;
  }
  token.value[0] = '\0';

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isalpha(*cursor)) {
      if (!strcmp(token.value, "int")) {
        token.type = INT;
        printf("INT TYPE Found!!\n");
      } else if (!strcmp(token.value, "float")) {
        token.type = FLOAT;
        printf("FLOAT TYPE Found!!\n");
      } else {
        token.type = IDENTIFIER;
        printf("IDENTIFIER Found!!\n");
      }

      printf("%s\n", token.value);
      ungetc(*(cursor), file);
      return token;
    }

    char *tmp = (char *)realloc(token.value, (strlen(token.value) + 2));
    if (tmp == NULL) {
      free(token.value);
      token.value = NULL;
      perror("Memory reallocation failed for the current token value.\n");
      exit(EXIT_FAILURE);
    }

    token.value = tmp;

    size_t len = strlen(token.value);
    token.value[len] = *cursor;
    token.value[len + 1] = '\0';
  }

  return token;
}

TokenList *lexer(FILE *file) {
  char cursor;
  Token token;
  TokenList *tokenList = createTokenList();

  while ((cursor = fgetc(file)) != EOF) {
    if (cursor == ' ')
      continue;
    else if (cursor == '@') {
      char value = cursor + '\0';
      token = createToken(ALGO, &value);
      printf("ALGO FOUND!!\n");
      printf("Token value : %s!!\n", token.value);
      printf("Token type : %d\n", token.type);
      printf("*****\n\n");
    } else if (cursor == ':') {
      char value = cursor + '\0';
      token = createToken(COLON, &value);
      printf("COLONS Found!!\n");
      printf("Token value : %s!!\n", token.value);
      printf("Token type : %d\n", token.type);
      printf("*****\n\n");
    } else if (cursor == '=') {
      char value = cursor + '\0';
      token = createToken(AFFECT, &value);
      printf("AFFECT FOUND!!\n");
      printf("Token value : %s!!\n", token.value);
      printf("Token type : %d\n", token.type);
      printf("*****\n\n");
    } else if (cursor == ';') {
      char value = cursor + '\0';
      token = createToken(SEMI, &value);
      printf("SEMICOLONS Found!!\n");
      printf("Token value : %s!!\n", token.value);
      printf("Token type : %d\n", token.type);
      printf("*****\n\n");
    } else if (isalpha(cursor)) {
      token = identifyAlphanum(&cursor, file);
      printf("Token value : %s!!\n", token.value);
      printf("Token type : %d\n", token.type);
      printf("*****\n\n");
    } else if (isdigit(cursor)) {
      token = isNumber(&cursor, file);
      printf("NUMBER found!!\n\n");
      printf("Token value : %s!!\n", token.value);
      printf("Token type : %d\n", token.type);
      printf("*****\n\n");
    }

    tokenList = addTokenEnd(tokenList, token);
  }

  return tokenList;
}
