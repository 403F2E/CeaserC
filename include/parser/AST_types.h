
#ifndef _AST_TYPES_H
#define _AST_TYPES_H

#include <stdbool.h>
#include <stddef.h>

#include "../core/token.h"

struct ASTProgram {
  struct ASTIdentifier *program_name;

  struct ASTNode **modules;
  size_t modules_count;
};

struct ASTBlock {
  struct ASTNode **statements;
  size_t statement_count;
};

struct ASTLiteral {
  struct Token literal;
};

struct ASTIdentifier {
  char *name;
  struct Symbol *symbol;
};

struct ASTVarDecl {
  struct ASTIdentifier *ident;
  struct Type *type;
  struct ASTNode *initializer;
};

struct ASTCall {
  struct ASTNode *callee;

  struct ASTNode **arguments;
  size_t argument_count;
};

struct ASTMod {
  struct ASTIdentifier *mod_name;

  struct ASTNode **declarations;
  size_t declarations_count;
};

struct ASTUse {
  char *path;
  struct ASTIdentifier *alias;
};

struct ASTField {
  struct ASTIdentifier *field_name;
  struct Type *type;
};

struct ASTStruct {
  struct ASTIdentifier *struct_name;

  bool is_pub;

  struct ASTField **fields;
  size_t fields_count;
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

struct ASTParameter {
  struct ASTIdentifier *param;
  struct Type *type;
};

struct ASTFunction {

  struct ASTIdentifier *func_name;

  struct ASTParameter **parameters;
  size_t parameter_count;

  struct Type *return_type;

  struct ASTBlock *body;

  struct Attribute *attributes;
  size_t attribute_count;
};

struct ASTBinaryExpr {
  struct ASTNode *left;
  struct ASTNode *right;
  struct Token op;
};

#endif
