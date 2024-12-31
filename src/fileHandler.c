
#include "../headers/fileHandler.h"

FILE *openFile(const char *file) {
  FILE *filestream = fopen(file, "r");

  if (filestream == NULL) {
    perror("Error opening file");
  }
  return filestream;
}
