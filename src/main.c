
#include "../headers/utils.h" // IWYU pragma: keep

void printTokenList(TokenList *tokenlist) {
  TokenList *current = tokenlist->tail;

  while (current != tokenlist) {
    printf("The token value : %s\n", current->token.value);
    printf("The token type : %d\n", current->token.type);
    current = current->tail;
  }

  return;
}

int extVerifier(const char *filename, const char *extension) {
  size_t len_filename = strlen(filename);
  size_t len_ext = strlen(extension);

  if (len_filename >= len_ext &&
      !strcmp(filename + len_filename - len_ext, extension)) {
    return 0;
  }
  return 1;
}

int main(const int argc, const char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <FILE PATH to Compile> ...\n", argv[0]);
    return 1;
  }

  if (extVerifier(argv[1], ".rzc")) {
    printf("Error: Unsupported file extension. Please use .kno\n");
    return 1;
  }

  FILE *file = openFile(argv[1]);

  TokenList *tokenList = lexer(file);
  printf("\n******\n");
  printTokenList(tokenList);

  fclose(file);
  return 0;
}
