
#ifndef _TYPE_H
#define _TYPE_H

#include <stdbool.h>
#include <stddef.h>

enum TypeKind {
  TYPE_VOID,
  TYPE_NONE,
  TYPE_F32,
  TYPE_F64,
  TYPE_I8,
  TYPE_I16,
  TYPE_I32,
  TYPE_I64,
  TYPE_CHAR,
  TYPE_STR,
  TYPE_BIT,
  TYPE_BITS,
  TYPE_BYTE,
  TYPE_WORD,
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_BOOL,

  TYPE_POLY,
  TYPE_FIELD,
  TYPE_GROUP,
  TYPE_LATTICE,

  TYPE_STRING,

  TYPE_STRUCT,
  TYPE_FUNCTION,

  TYPE_UNKNOWN
};

struct Type {
  enum TypeKind kind;
  size_t bit_width;
  bool is_const;
  bool is_secret;
};

#endif
