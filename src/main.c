#include <stdlib.h>

#include "../headers/Tokenizer.h"
#include "../headers/fileHandler.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <FILE PATH to Compile> ...\n", argv[0]);
    return 1; // Return an error code if no arguments are passed
  }
  FILE *file = openFile(argv[1]);
  return 0;
}
