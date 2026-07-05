
#include "../../include/parser/parser.h"
#include "../../include/core/core.h"

// static struct Token *peek(struct Parser *);
// static struct Token *previous(struct Parser *);
// static struct Token *advance(struct Parser *);
// static bool match(struct Parser *, enum TOKENTYPE);
// static struct Token *consume(struct Parser *, enum TOKENTYPE,
//                              const char *message);
// static bool is_at_end(struct Parser *);

struct ASTNode *parser(struct TokenList *tokenlist) {
  struct TokenList *token_list = tokenlist;

  struct ASTNode *ast_tree = NULL;

  printf("%s : %d\n", token_list->token->lexeme, token_list->token->type);

  return ast_tree;
}
