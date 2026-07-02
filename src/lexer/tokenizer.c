
#include "../../include/lexer/tokenizer.h"
#include "../../include/core/token_list.h"

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_TOKEN_CAPACITY 64

// Create Token instance
Token tokenize(Lexer *lexer, TOKENTYPE type) {
  Token token;

  token.type = type;
  token.lexeme = lexer->start;
  token.length = lexer->current - lexer->start;
  token.line = lexer->line;
  token.column = lexer->column;

  return token;
}

// Create Token List instance
TokenList *create_token_list() {
  TokenList *list = malloc(sizeof(TokenList));

  if (!list)
    return NULL;

  list->token = malloc(sizeof(Token) * INITIAL_TOKEN_CAPACITY);

  if (!list->token) {
    free(list);
    return NULL;
  }

  list->count = 0;
  list->capacity = INITIAL_TOKEN_CAPACITY;

  return list;
}

// Double the capacity and realloc the list
static bool grow_token_list(TokenList *list) {
  size_t new_capacity = list->capacity * 2;

  Token *new_data = realloc(list->token, sizeof(Token) * new_capacity);

  if (!new_data)
    return 0;

  list->token = new_data;
  list->capacity = new_capacity;

  return 1;
}

// Add token to the end of the token list
bool push_token_list(TokenList *list, Token token) {
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
void token_list_destroy(TokenList *list) {
  if (!list)
    return;

  free(list->token);
  free(list);
}

Token *token_at(TokenList *list, size_t index) {
  if (index >= list->count)
    return NULL;

  return &list->token[index];
}

// Pretty formatting gathered tokens
void printTokenList(TokenList *tokenlist) {
  for (int i = 0; i < tokenlist->count; i++) {
    printf("[TYPE:%d] [LEXEME:%.*s]\n", tokenlist->token[i].type,
           (int)tokenlist->token[i].length, tokenlist->token[i].lexeme);
  }
  return;
}
