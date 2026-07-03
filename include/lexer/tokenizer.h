
#ifndef _TOKENIZER_H
#define _TOKENIZER_H

#include "../core/token_list.h"
#include <stdio.h>

struct Lexer {
  const char *filename;
  const char *source;
  const char *current;
  const char *start;
  size_t line;
  size_t column;
};

struct Token tokenize(struct Lexer *lexer, enum TOKENTYPE type);

struct TokenList *lexer_scan(struct Lexer lexer);

#endif
