
#pragma once

#include <ctype.h>
#include <stddef.h>

// List of Keyword of the language
typedef enum {
  IDENTIFIER,
  FUNC,
  CLASS,
  EXIT,

  // List of Sepcial Symbols of the language
  AFFECT,
  COLON,
  SEMI,
  OPEN_PAREN,
  CLOSE_PAREN,

  // List of Comparison Keyword of the language
  EQUAL,
  GTHAN,
  ITHAN,
  GT_EQUAL,
  IT_EQUAL,

  // List of Types built for the variable of the languge
  INT,
  FLOAT,
  CHAR,
  STRING,
  BOOL,

  // Special type of the language
  ALGO,

} TokenType;

/*** building the structs for each token type ***/

// Token Type literal
typedef struct {
  TokenType type;
  char *value;
} Token;

typedef struct TokenList {
  Token token;
  struct TokenList *head, *prev, *tail;
} TokenList;
