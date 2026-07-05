
#include "../include/utils.h"

int main(const int argc, const char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <FILE PATH to Compile> ...\n", argv[0]);
    return 1;
  }

  if (extension_verifier(argv[1], ".rzc")) {
    fprintf(stderr, "Error: Unsupported file extension. Please use .kno\n");
    return 1;
  }

  struct Lexer lexer = {
      .filename = argv[1],
      .source = read_file(argv[1]),
      .start = lexer.source,
      .current = lexer.source,
      .column = 1,
      .line = 1,
  };

  struct TokenList *tokenList = lexer_scan(&lexer);
  printf("\n******\n");
  printTokenList(tokenList);

  struct Parser parser = {
      .tokens = (struct TokenList *)_malloc(sizeof(struct TokenList)),
      .current = tokenList->count,
      .had_error = false};

  parser.tokens = tokenList;

  struct ASTNode *ast = parse_program(&parser);

  tokenList = NULL;
  // ast = NULL;

  free(tokenList);
  free(ast);
  return 0;
}
