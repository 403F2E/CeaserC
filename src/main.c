
#include "../include/utils.h"

int main(const int argc, const char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <FILE PATH to Compile> ...\n", argv[0]);
    return 1;
  }

  if (extension_verifier(argv[1], ".rzc")) {
    printf("Error: Unsupported file extension. Please use .kno\n");
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

  struct TokenList *tokenList = lexer_scan(lexer);
  printf("\n******\n");
  printTokenList(tokenList);

  // AST_Tree *ast = parser(tokenList);

  tokenList = NULL;
  // ast = NULL;

  free(tokenList);
  // free(ast);
  return 0;
}
