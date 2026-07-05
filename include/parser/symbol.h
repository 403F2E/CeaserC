
#ifndef _SYMBOL_H
#define _SYMBOL_H

#include <stddef.h>

enum SymbolKind {
  SYMBOL_VARIABLE,
  SYMBOL_PARAMETER,
  SYMBOL_FUNCTION,
  SYMBOL_STRUCT,
  SYMBOL_FIELD,
  SYMBOL_TYPE,
  SYMBOL_MODULE,
  SYMBOL_CONSTANT
};

struct Symbol {
  char *name;

  enum SymbolKind kind;

  struct Type *type;

  struct ASTNode *declaration;

  size_t scope_level;

  bool is_public;
  bool is_secret;
  bool is_constant;
};

#endif
