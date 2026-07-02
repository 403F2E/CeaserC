#ifndef _TOKEN_LIST_H
#define _TOKEN_LIST_H

#include "token.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct {
  Token *token;
  size_t count;
  size_t capacity;
} TokenList;

TokenList *create_token_list(void);

bool push_token_list(TokenList *list, Token token);

void destroy_token_list(TokenList *list);

void printTokenList(TokenList *tokenlist);

#endif
