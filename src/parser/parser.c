
#include "../../include/parser/parser.h"
#include "../../include/core/core.h"

// static struct Token *peek(struct Parser *);
// static struct Token *previous(struct Parser *);
// static struct Token *advance(struct Parser *);
// static bool match(struct Parser *, enum TOKENTYPE);
// static struct Token *consume(struct Parser *, enum TOKENTYPE,
//                              const char *message);
// static bool is_at_end(struct Parser *);

struct ASTNode *parse_program(struct Parser *parser) {

  struct ASTNode *ast_tree = (struct ASTNode *)_malloc(sizeof(struct ASTNode));
  ast_tree->kind = AST_PROGRAM;
  ast_tree->token = (struct Token *)_malloc(sizeof(struct Token));
  ast_tree->parent = NULL;
  ast_tree->binary_expr = NULL;

  return ast_tree;
}
