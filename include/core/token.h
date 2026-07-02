
#ifndef _TOKEN_H
#define _TOKEN_H

#include <ctype.h>
#include <stddef.h>

// List of Keyword of the language
typedef enum {
  TOKEN_IDENTIFIER,
  TOKEN_KEYWORD,
  TOKEN_STRING,
  TOKEN_NUMERIC,
  TOKEN_SYMBOL,
  // TOKEN_COMPARISON,
  TOKEN_ESCSEQ,
  TOKEN_EOF,
  TOKEN_UNKNOWN
} TOKENTYPE;

/*** TODO: building the structs for each token type ***/

// Token Type literal
typedef struct {
  TOKENTYPE type;
  const char *lexeme;
  size_t length;
  size_t line;
  size_t column;
} Token;

#endif
