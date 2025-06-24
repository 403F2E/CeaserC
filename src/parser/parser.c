
#include "parser.h"
#include <stdio.h>
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

AST_unit parse_indent(Token token) {
  AST_unit unit;
  if (!strcmp(token.value, "const")) {
    unit.string = token.value;
    unit.type = CONST;
  } else if (!strcmp(token.value, "binary")) {
    unit.string = token.value;
    unit.type = BIN;
  } else if (!strcmp(token.value, "oct")) {
    unit.string = token.value;
    unit.type = FLOAT;
  } else if (!strcmp(token.value, "hex")) {
    unit.string = token.value;
    unit.type = FLOAT;
  } else if (!strcmp(token.value, "int")) {
    unit.string = token.value;
    unit.type = INT;
  } else if (!strcmp(token.value, "float")) {
    unit.string = token.value;
    unit.type = FLOAT;
  } else if (!strcmp(token.value, "double")) {
    unit.string = token.value;
    unit.type = DOUBLE;
  } else if (!strcmp(token.value, "char")) {
    unit.string = token.value;
    unit.type = CHAR;
  } else if (!strcmp(token.value, "bool")) {
    unit.string = token.value;
    unit.type = BOOL;
  } else if (!strcmp(token.value, "key")) {
    unit.string = token.value;
    unit.type = KEY;
  } else if (!strcmp(token.value, "ciph")) {
    unit.string = token.value;
    unit.type = CIPHER;
  } else {
    unit.string = token.value;
    unit.type = IDENTIFY;
  }
  return unit;
}

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
    tokenlst = tokenlst->tail;
  }
  return ast_tree;
}

AST_Tree *parser(TokenList *tokenlist) {
  TokenList *headtoken = tokenlist;

  AST_Tree *ast_tree = fill_AST_Tree(tokenlist);

  printf("%s : %d\n", headtoken->token.value, headtoken->token.type);
  return ast_tree;
}
