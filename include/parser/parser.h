
#ifndef _PARSER_H
#define _PARSER_H

#include "../core/token_list.h"

enum ASTKIND {
  AST_PROGRAM,
  AST_FUNCTION,
  AST_BLOCK,
  AST_IF,
  AST_FOR,
  AST_WHILE,
  AST_RETURN,
  AST_ASSIGN,
  AST_BINARY,
  AST_UNARY,
  AST_CALL,
  AST_IDENTIFIER,
  AST_LITERAL,
  AST_STRUCT,
  AST_MATCH
};

struct AST_unit {
  enum ASTKIND type;
  union {
    double numeric;
    char *string;
  };
};

struct AST_Tree {
  struct AST_unit unit;
  struct AST_Tree *next, *prev;
};

struct AST_Tree *parser(struct TokenList *);

#endif
