
#ifndef _TOKEN_H
#define _TOKEN_H

#include <ctype.h>
#include <stddef.h>

#define MAX_IDENT_LEN 1024

#define BASE_LIST                                                              \
  X(TOKEN_IDEN, "IDENT")                                                       \
  X(TOKEN_STRING, "STRING")                                                    \
  X(TOKEN_NUMERIC, "NUMERIC")                                                  \
  X(TOKEN_UNKNOWN, "UNKNOWN")

#define SYMBOL_LIST                                                            \
  X(TOKEN_EOF, "\0")                                                           \
  X(TOKEN_LPAREN, "(")                                                         \
  X(TOKEN_RPAREN, ")")                                                         \
  X(TOKEN_LCBRACE, "{")                                                        \
  X(TOKEN_RCBRACE, "}")                                                        \
  X(TOKEN_COLON, ":")                                                          \
  X(TOKEN_SEMI, ";")                                                           \
  X(TOKEN_ASSIGN, "=")                                                         \
  X(TOKEN_COMMA, ",")                                                          \
  X(TOKEN_PLUS, "+")                                                           \
  X(TOKEN_MINUS, "-")                                                          \
  X(TOKEN_DIV, "/")                                                            \
  X(TOKEN_MUL, "*")                                                            \
  X(TOKEN_MOD, "%")                                                            \
  X(TOKEN_EQ, "==")                                                            \
  X(TOKEN_LT, "<")                                                             \
  X(TOKEN_GT, ">")                                                             \
  X(TOKEN_LTE, "<=")                                                           \
  X(TOKEN_GTE, ">=")                                                           \
  X(TOKEN_RANGE, ":=")

#define KEYWORD_LIST                                                           \
  X(TOKEN_NONE, "None")                                                        \
  X(TOKEN_USE, "use")                                                          \
  X(TOKEN_AS, "as")                                                            \
  X(TOKEN_LET, "let")                                                          \
  X(TOKEN_FLOAT, "float")                                                      \
  X(TOKEN_INT, "int")                                                          \
  X(TOKEN_BIT, "bit")                                                          \
  X(TOKEN_BITS, "bits")                                                        \
  X(TOKEN_BYTE, "byte")                                                        \
  X(TOKEN_TRUE, "true")                                                        \
  X(TOKEN_FALSE, "false")                                                      \
  X(TOKEN_WORD, "word")                                                        \
  X(TOKEN_STRUCT, "struct")                                                    \
  X(TOKEN_IF, "if")                                                            \
  X(TOKEN_ELSE, "else")                                                        \
  X(TOKEN_ELIF, "elif")                                                        \
  X(TOKEN_MATCH, "match")                                                      \
  X(TOKEN_CASE, "case")                                                        \
  X(TOKEN_FINALLY, "finally")                                                  \
  X(TOKEN_AND, "and")                                                          \
  X(TOKEN_OR, "or")                                                            \
  X(TOKEN_FOR, "for")                                                          \
  X(TOKEN_IN, "in")                                                            \
  X(TOKEN_WHILE, "while")                                                      \
  X(TOKEN_DOWHILE, "dowhile")                                                  \
  X(TOKEN_TRY, "try")                                                          \
  X(TOKEN_CATCH, "catch")                                                      \
  X(TOKEN_POLY, "poly")                                                        \
  X(TOKEN_LATTICE, "lattice")                                                  \
  X(TOKEN_FIELD, "field")                                                      \
  X(TOKEN_GROUP, "group")                                                      \
  X(TOKEN_TYPE, "type")                                                        \
  X(TOKEN_QUBIT, "qubit")                                                      \
  X(TOKEN_QUREG, "qureg")                                                      \
  X(TOKEN_QCIRCUIT, "qcircuit")                                                \
  X(TOKEN_QGATE, "qgate")                                                      \
  X(TOKEN_MEASURE, "measure")                                                  \
  X(TOKEN_SUPERPOSE, "superpose")                                              \
  X(TOKEN_APPLY, "apply")                                                      \
  X(TOKEN_TRANSFORM, "transform")                                              \
  X(TOKEN_PERMUTE, "permute")                                                  \
  X(TOKEN_ROUND, "round")                                                      \
  X(TOKEN_WITH, "with")                                                        \
  X(TOKEN_ASSERT, "assert")                                                    \
  X(TOKEN_ASSUME, "assume")                                                    \
  X(TOKEN_RETURN, "return")                                                    \
  X(TOKEN_YIELD, "yield")                                                      \
  X(TOKEN_ADD_MOD, "add_mod")                                                  \
  X(TOKEN_MUL_MOD, "mul_mod")                                                  \
  X(TOKEN_EXP_MOD, "exp_mod")                                                  \
  X(TOKEN_INV_MOD, "inv_mod")                                                  \
  X(TOKEN_SAMPLE, "sample")                                                    \
  X(TOKEN_COMPRESS, "compress")                                                \
  X(TOKEN_DECOMPRESS, "decompress")                                            \
  X(TOKEN_HASH, "hash")                                                        \
  X(TOKEN_VERIFIABLE, "@verifiable")                                           \
  X(TOKEN_CONSTTIME, "@constant_time")                                         \
  X(TOKEN_PURE, "@pure")                                                       \
  X(TOKEN_LEAK_FREE, "@leak_free")                                             \
  X(TOKEN_PROVE, "prove")                                                      \
  X(TOKEN_INVARIANT, "invariant")                                              \
  X(TOKEN_REQUIRES, "requires")                                                \
  X(TOKEN_SECRET, "secret")                                                    \
  X(TOKEN_PUBLIC, "pub")                                                       \
  X(TOKEN_ZEROIZE, "zeroize")                                                  \
  X(TOKEN_CONSTANT, "const")                                                   \
  X(TOKEN_VOLATILE, "volatile")                                                \
  X(TOKEN_ALIGNED, "aligned")                                                  \
  X(TOKEN_NAMESPACE, "namespace")                                              \
  X(TOKEN_IMPORT, "import")                                                    \
  X(TOKEN_EXPORT, "export")                                                    \
  X(TOKEN_OPAQUE, "opaque")                                                    \
  X(TOKEN_INFINITY, "INF")

// List of Keyword of the language
enum TOKENTYPE {
#define X(type, name) type,
  BASE_LIST SYMBOL_LIST KEYWORD_LIST
#undef X
};

// Token Type literal
struct Token {
  enum TOKENTYPE type;
  const char *lexeme;
  size_t length;
  size_t line;
  size_t column;
};

#endif
