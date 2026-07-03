
#include "../../include/parser/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AST_Tree *createASTObject() {
  AST_Tree *ast = (AST_Tree *)malloc(sizeof(AST_Tree));
  if (ast == NULL) {
    perror("Error allocating memory for AST object");
    exit(EXIT_FAILURE);
  }
  ast->next = ast->prev = ast;
  return ast;
}

AST_unit parse_indent(struct Token token) {
  AST_unit unit = {0};
  // if (!strcmp(token.lexeme, "const")) {
  //   unit.string = token.lexeme;
  //   unit.type = CONST;
  // } else if (!strcmp(token.lexeme, "binary")) {
  //   unit.string = token.lexeme;
  //   unit.type = BIN;
  // } else if (!strcmp(token.lexeme, "oct")) {
  //   unit.string = token.lexeme;
  //   unit.type = FLOAT;
  // } else if (!strcmp(token.lexeme, "hex")) {
  //   unit.string = token.lexeme;
  //   unit.type = FLOAT;
  // } else if (!strcmp(token.lexeme, "int")) {
  //   unit.string = token.lexeme;
  //   unit.type = INT;
  // } else if (!strcmp(token.lexeme, "float")) {
  //   unit.string = token.lexeme;
  //   unit.type = FLOAT;
  // } else if (!strcmp(token.lexeme, "double")) {
  //   unit.string = token.lexeme;
  //   unit.type = DOUBLE;
  // } else if (!strcmp(token.lexeme, "char")) {
  //   unit.string = token.lexeme;
  //   unit.type = CHAR;
  // } else if (!strcmp(token.lexeme, "bool")) {
  //   unit.string = token.lexeme;
  //   unit.type = BOOL;
  // } else if (!strcmp(token.lexeme, "key")) {
  //   unit.string = token.lexeme;
  //   unit.type = KEY;
  // } else if (!strcmp(token.lexeme, "ciph")) {
  //   unit.string = token.lexeme;
  //   unit.type = CIPHER;
  // } else {
  //   unit.string = token.lexeme;
  //   unit.type = IDENTIFY;
  // }
  return unit;
}

AST_Tree *fill_AST_Tree(struct TokenList *tokenlist) {
  struct TokenList *tokenlst = tokenlist;
  AST_Tree *ast_tree = createASTObject();
  for (int i = 0; i < tokenlist->count; i++) {
    if (!tokenlst[i].token->type) {
      printf("todo!");
    } else if (tokenlst[i].token->type == 1) {
      printf("todo!");
    } else if (tokenlst[i].token->type == 2) {
      printf("todo!");
    } else if (tokenlst[i].token->type == 3) {
      printf("todo!");
    } else if (tokenlst[i].token->type == 4) {
      printf("todo!");
    } else if (tokenlst->token->type == 5) {
      printf("todo!");
    }
  }
  return ast_tree;
}

AST_Tree *parser(struct TokenList *tokenlist) {
  struct TokenList *headtoken = tokenlist;

  AST_Tree *ast_tree = fill_AST_Tree(tokenlist);

  printf("%s : %d\n", headtoken->token->lexeme, headtoken->token->type);
  return ast_tree;
}
