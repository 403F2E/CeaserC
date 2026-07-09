
#include "../../include/parser/parser.h"
#include "../../include/core/core.h"

#include "../../include/core/diagnostic.h"

static bool is_at_end(struct Parser *parser) {
  return parser->tokens->token[parser->current].type == TOKEN_EOF;
}

static struct Token *peek(struct Parser *parser) {
  return &parser->tokens->token[parser->current];
}

static struct Token *previous(struct Parser *parser) {
  return &parser->tokens->token[parser->current - 1];
}

static struct Token *advance(struct Parser *parser) {
  if (!is_at_end(parser))
    parser->current++;

  return previous(parser);
}

static bool match(struct Parser *parser, enum TOKENTYPE type) {
  if (peek(parser)->type != type)
    return false;

  advance(parser);
  return true;
}

static struct Token *consume(struct Parser *parser, enum TOKENTYPE type,
                             const char *message) {
  if (peek(parser)->type == type)
    return advance(parser);

  diagnostic_error("parser.h", peek(parser)->line, peek(parser)->column,
                   message);

  return NULL;
}

struct ASTNode *parse_program(struct Parser *parser) {

  struct ASTNode *ast_tree = (struct ASTNode *)_malloc(sizeof(struct ASTNode));
  ast_tree->kind = AST_PROGRAM;
  ast_tree->token = parser->tokens->token[1];
  ast_tree->parent = NULL;
  ast_tree->program.program_name = NULL;
  ast_tree->program.modules = NULL;
  ast_tree->program.modules_count = 0;

  while (!is_at_end(parser)) {
    // UNIMPLEMENTED!
  }

  return ast_tree;
}
