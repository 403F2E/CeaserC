#ifndef _TOKEN_LIST_H
#define _TOKEN_LIST_H

#include "token.h"
#include <stdbool.h>
#include <stddef.h>

struct TokenList {
  struct Token *token;
  size_t count;
  size_t capacity;
};

struct TokenList *create_token_list(void);

bool push_token_list(struct TokenList *, struct Token);

void destroy_token_list(struct TokenList *);

char *token_type_str(enum TOKENTYPE);

void printTokenList(struct TokenList *);

#endif
