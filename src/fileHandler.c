
#include "../headers/utils.h"

FILE *openFile(const char *file) {
  FILE *filestream = fopen(file, "r");

  if (filestream == NULL) {
    perror("Error opening file");
  }
  return filestream;
}
