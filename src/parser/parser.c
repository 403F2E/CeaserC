
#include "parser.h"
#include <stdio.h>

AST_Tree *createASTObject() {
  AST_Tree *ast = (AST_Tree *)malloc(sizeof(AST_Tree));
  if (ast == NULL) {
    perror("Error allocating memory for AST object");
    exit(EXIT_FAILURE);
  }
  ast->next = ast->prev = ast;
  return ast;
}

AST_unit parse_value();

AST_Tree *fill_AST_Tree(TokenList *tokenlist) {
  TokenList *tokenlst = tokenlist;
  AST_Tree *ast_tree = createASTObject();
  while (tokenlst != NULL) {
    if (!tokenlst->token.type) {
      printf("todo!");
    } else if (tokenlst->token.type == 1) {
      printf("todo!");
    } else if (tokenlst->token.type == 2) {
      printf("todo!");
    } else if (tokenlst->token.type == 3) {
      printf("todo!");
    } else if (tokenlst->token.type == 4) {
      printf("todo!");
    } else if (tokenlst->token.type == 5) {
      printf("todo!");
    }
  }
  return ast_tree;
}

AST_Tree *parser(TokenList *tokenlist) {
  TokenList *headtoken = tokenlist;

  AST_Tree *ast_tree = fill_AST_Tree(tokenlist);

  printf("%s : %d\n", headtoken->token.value, headtoken->token.type);
  return ast_tree;
}
