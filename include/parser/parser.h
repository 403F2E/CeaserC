
#ifndef _PARSER_H
#define _PARSER_H

#include "../core/token_list.h"
#include "../core/types.h"
#include <stdint.h>

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
  AST_DECLARATION,
  AST_CALL,
  AST_IDENTIFIER,
  AST_LITERAL,
  AST_STRUCT,
  AST_MATCH
};

struct ASTVarDecl {
  char *name;
  struct Type *type;
  struct ASTNode *initializer;
};

struct ASTBinaryExpr {
  struct ASTNode *left;
  struct ASTNode *right;
  struct Token op;
};

enum AttributeKind {
  ATTR_PURE,
  ATTR_VERIFIABLE,
  ATTR_CONSTANT_TIME,
  ATTR_LEAK_FREE
};

struct Attribute {
  enum AttributeKind kind;
};

struct ASTFunction {
  char *name;

  struct ASTNode *parameters;
  size_t parameter_count;

  struct Type *return_type;

  struct ASTNode *body;

  struct Attribute *attributes;
  size_t attribute_count;
};

struct ASTNode {
  enum ASTKIND kind;

  struct Token token;

  struct Type *resolved_type;

  union {
    struct ASTBinaryExpr binary_expr;
    struct ASTFunction function;
    struct ASTVarDecl var_dec;
  };
};

struct ASTNode *parser(struct TokenList *);

#endif
