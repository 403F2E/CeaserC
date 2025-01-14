
#include "../headers/utils.h"

int main(const int argc, const char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <FILE PATH to Compile> ...\n", argv[0]);
    return 1;
  }

  FILE *file = openFile(argv[1]);

  lexer(file);

  fclose(file);
  return 0;
}
