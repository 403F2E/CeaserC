

#pragma once
#include "../../include/utils.h"

typedef enum {
  CONST,
  INT,
  BIN,
  OCT,
  HEX,
  FLOAT,
  DOUBLE,
  CHAR,
  BOOL,
  KEY,
  CIPHER,
} PARSED_TYPES;

typedef enum {
  IDENT,
  DEF,
  CLASS,
  ALGO,
  RETURN,
  IF,
  ELSE,
  FOR,
  WHILE,
  DO,
  BREAK,
  CONTINUE,
  MATCH,
  DEFAULT,
} PARSED_KEYWORD;

typedef enum {
  LT,
  LE,
  EQ,
  NE,
  GE,
  GT,
  ADD,
  SUB,
  MUL,
  DIV,
  MOD,
  ASSIGN,
  INC,
  DEC,
  RANGE,
  POWER,
  LOGICAL_AND,
  LOGICAL_OR,
  LOGICAL_NOT,
  BITWISE_AND,
  BITWISE_OR,
  BITWISE_XOR,
  BITWISE_NOT,
  BITWISE_SHL,
  BITWISE_RSHL,
} PARSED_SYMBOLS;

typedef struct AST_unit {
  union {
    double numeric;
    char *string;
  };
  union {
    PARSED_TYPES type;
    PARSED_KEYWORD keyword;
    PARSED_SYMBOLS symbol;
  };
} AST_unit;

typedef struct AST_Tree {
  AST_unit unit;
  struct AST_Tree *next, *prev;
} AST_Tree;

AST_Tree *parser(TokenList *);
