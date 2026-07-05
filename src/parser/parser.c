
#include "../../include/parser/parser.h"
#include "../../include/core/core.h"
#include <stdio.h>

struct ASTNode *parser(struct TokenList *tokenlist) {
  struct TokenList *token_list = tokenlist;

  struct ASTNode *ast_tree = NULL;

  printf("%s : %d\n", token_list->token->lexeme, token_list->token->type);

  return ast_tree;
}
