
#include "../../include/lexer/tokenizer.h"
#include "../../include/core/core.h"
#include "../../include/core/token_list.h"

#define TOSTR(type) #type;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_TOKEN_CAPACITY 64

// Create Token instance
struct Token tokenize(struct Lexer *lexer, enum TOKENTYPE type) {
  struct Token token;

  token.type = type;
  token.lexeme = lexer->start;
  token.length = lexer->current - lexer->start;
  token.line = lexer->line;
  token.column = lexer->column;

  return token;
}

// Create Token List instance
struct TokenList *create_token_list() {
  struct TokenList *list = _malloc(sizeof(struct TokenList));

  if (!list)
    return NULL;

  list->token = _malloc(sizeof(struct Token) * INITIAL_TOKEN_CAPACITY);

  if (!list->token) {
    free(list);
    return NULL;
  }

  list->count = 0;
  list->capacity = INITIAL_TOKEN_CAPACITY;

  return list;
}

// Double the capacity and realloc the list
static bool grow_token_list(struct TokenList *list) {
  size_t new_capacity = list->capacity * 2;

  struct Token *new_data =
      _realloc(list->token, sizeof(struct Token) * new_capacity);

  if (!new_data)
    return 0;

  list->token = new_data;
  list->capacity = new_capacity;

  return 1;
}

// Add token to the end of the token list
bool push_token_list(struct TokenList *list, struct Token token) {
  if (!list)
    return 0;

  if (list->count >= list->capacity) {
    if (!grow_token_list(list))
      return 0;
  }

  list->count++;
  list->token[list->count] = token;

  return 1;
}

// Delete the TokenList
void token_list_destroy(struct TokenList *list) {
  if (!list)
    return;

  free(list->token);
  free(list);
}

struct Token *token_at(struct TokenList *list, size_t index) {
  if (index >= list->count)
    return NULL;

  return &list->token[index];
}

char *token_type_to_str(enum TOKENTYPE type) {
  switch (type) {
#define X(type, name)                                                          \
  case type:                                                                   \
    return #type;
    BASE_LIST
    SYMBOL_LIST
    KEYWORD_LIST
#undef X
  default:
    return "TOKEN_UNKNOWN";
  }
}

// Pretty formatting gathered tokens
void printTokenList(struct TokenList *tokenlist) {
  char *type = (char *)_malloc(17);
  for (int i = 1; i < tokenlist->count; i++) {
    type = token_type_to_str(tokenlist->token[i].type);
    printf("[TYPE: %d %s] [LEXEME: %.*s]\n", tokenlist->token[i].type, type,
           (int)tokenlist->token[i].length, tokenlist->token[i].lexeme);
  }
  return;
}
