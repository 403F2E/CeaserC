
#include "../headers/fileHandler.h"

FILE *openFile(const char *file) {
  FILE *file = fopen(file, 'r');
  return &file;
}
