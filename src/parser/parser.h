

#pragma once
#include "../../headers/utils.h"

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

typedef struct AST_object {
  union {
    int placeholder;
  };
  struct AST_object *next, *prev;
} AST_object;

AST_object *parser(TokenList *);
