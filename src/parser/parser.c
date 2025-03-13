
#include "parser.h"
#include "../../headers/utils.h" // IWYU pragma: keep
#include <stdio.h>

AST_object *createASTObject() {
  AST_object *ast = (AST_object *)malloc(sizeof(AST_object));
  if (ast == NULL) {
    perror("Error allocating memory for AST object");
    exit(EXIT_FAILURE);
  }
  ast->next = ast->prev = ast;
  return ast;
}

AST_object *parser(TokenList *tokenlist) {
  TokenList *headtoken = tokenlist;
  AST_object *ast = createASTObject();
  printf("%s%d", headtoken->token.value, headtoken->token.type);
  return ast;
}
