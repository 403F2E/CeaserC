
#ifndef _PARSER_H
#define _PARSER_H

#include "../core/token_list.h"
#include "AST_types.h"

/** FLAGS HERE **/
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

/** TYPES HERE **/

struct ASTNode {
  enum ASTKIND kind;

  struct Token token;

  struct ASTNode *parent;

  union {
    struct ASTProgram program;
    struct ASTMod mod;
    struct ASTUse use;
    struct ASTStruct strct;
    struct ASTFunction function;
    struct ASTBinaryExpr binary_expr;
    struct ASTVarDecl var_dec;
    struct ASTCall call;
  };
};

struct Parser {
  struct TokenList *tokens;

  size_t current;

  bool had_error;
};

/** FUNCTIONS HERE **/
struct ASTNode *parse_program(struct Parser *);
struct ASTNode *create_new_ast(enum ASTKIND);

#endif
