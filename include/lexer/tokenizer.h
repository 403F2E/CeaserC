
#ifndef _TOKENIZER_H
#define _TOKENIZER_H

#include "../core/token_list.h"
#include <stdio.h>

typedef struct {
  const char *filename;
  const char *source;
  const char *current;
  const char *start;
  size_t line;
  size_t column;
} Lexer;

Token tokenize(Lexer *lexer, TOKENTYPE type);

TokenList *lexer_scan(Lexer lexer);

#endif
