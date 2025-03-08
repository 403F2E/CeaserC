
#pragma once

#include <ctype.h>
#include <stddef.h>

// List of Keyword of the language
typedef enum {
  IDENTIFIER,
  NUMERIC,
  KEYWORD,
  SYMBOL,
  COMPARISON,
  ESCSEQ,
} TOKENTYPE;

/*** building the structs for each token type ***/

// Token Type literal
typedef struct {
  TOKENTYPE type;
  char *value;
} Token;

typedef struct TokenList {
  Token token;
  struct TokenList *prev, *tail;
} TokenList;
