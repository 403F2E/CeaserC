
#include "lexer.h"
#include "Tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create Token instance
Token tokenizer(int type, char *value) {
  Token token;
  token.type = type;

  token.value = (char *)malloc(sizeof(value));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed for the current token value.\n");
    exit(EXIT_FAILURE);
  }

  strcpy(token.value, value);
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

  tokenList->tail = tokenList;

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
  newTokenNode->tail = NULL;
  tokenList->tail = newTokenNode;

  return tokenList;
}

// function determine the whole number
Token identifyNumber(char *cursor, FILE *file) {
  ungetc(*cursor, file);

  Token token;
  token.type = NUMERIC;
  token.value = (char *)malloc(sizeof(char));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed for the current token value.\n");
    exit(EXIT_FAILURE);
  }
  token.value[0] = '\0';

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isdigit(*cursor) && *cursor != '.') {
      ungetc(*cursor, file);
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
  ungetc(*cursor, file);
  Token token;
  token.type = KEYWORD;
  token.value = (char *)malloc(sizeof(char));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed.\n");
    return token;
  }
  token.value[0] = '\0';

  while ((*cursor = fgetc(file)) != EOF) {
    if (!isalpha(*cursor)) {
      ungetc(*cursor, file);
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

/*** The process to identify symbols ***/
bool issymbol(char cursor) {
  return (cursor == ':' || cursor == ';' || cursor == '@' || cursor == '=' ||
          cursor == '(' || cursor == ')' || cursor == '{' ||
          cursor == '}'); // symbols currently identified
}

// identify the symbol
Token identifySymbol(char *cursor, FILE *file) {
  Token token;
  token.type = SYMBOL;
  token.value = (char *)malloc(sizeof(char));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed.\n");
    return token;
  }

  token.value[0] = *cursor;

  char range_check = fgetc(file);

  if (*cursor == ':' && range_check == '=') {

    char *tmp = (char *)realloc(token.value, (strlen(token.value) + 2));
    if (tmp == NULL) {
      free(token.value);
      token.value = NULL;
      perror("Memory reallocation failed for the current token value.\n");
      exit(EXIT_FAILURE);
    }

    token.value = tmp;

    size_t len = strlen(token.value);
    token.value[len] = range_check;
    token.value[len + 1] = '\0';

    return token;
  }

  token.value[1] = '\0';

  return token;
}

/** The process to identify Escape Sequence **/
bool isescapeSeq(char cursor) {
  const char escapeseq[] = "\"\'\n\t\v\b\r\\";
  return strchr(escapeseq, cursor) != NULL;
}

char *whichEscSeq(char cursor) {
  switch (cursor) {
  case '\n':
    return "\\n";
  case '\t':
    return "\\t";
  case '\v':
    return "\\v";
  case '\r':
    return "\\r";
  case '\\':
    return "\\\\";
  case '\b':
    return "\\b";
  case '\'':
    return "\'";
  case '\"':
    return "\"";
  default:
    return "";
  }
}

Token identifyEscapeSequence(char *cursor, FILE *file) {
  Token token;
  token.type = ESCSEQ;
  token.value = (char *)malloc(sizeof(char));
  if (token.value == NULL) {
    free(token.value);
    perror("Memory allocation failed.\n");
    return token;
  }

  strcpy(token.value, whichEscSeq(*cursor));

  return token;
}

/*
 *
 */
TokenList *lexer(FILE *file) {
  char cursor;
  Token token;
  TokenList *tokenList = createTokenList();

  while ((cursor = fgetc(file)) != EOF) {
    if (cursor == ' ')
      continue;
    else if (isalpha(cursor))
      token = identifyAlphanum(&cursor, file);
    else if (isdigit(cursor))
      token = identifyNumber(&cursor, file);
    else if (issymbol(cursor))
      token = identifySymbol(&cursor, file);
    else if (isescapeSeq(cursor))
      token = identifyEscapeSequence(&cursor, file);
    else {
      fprintf(stderr, "Invalid charater %c.", cursor);
      exit(EXIT_FAILURE);
    }

    tokenList = addTokenEnd(tokenList, token);
  }

  char *value = (char *)malloc(sizeof(char));
  value = "EOF";
  token = tokenizer(EOF, value);

  tokenList = addTokenEnd(tokenList, token);

  return tokenList;
}
