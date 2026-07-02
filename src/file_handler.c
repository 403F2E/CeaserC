
#include "../include/file_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE *open_file(const char *file) {
  FILE *filestream = fopen(file, "r");

  if (filestream == NULL) {
    perror("Error opening file");
  }
  return filestream;
}

static long int get_file_size(FILE *file) {
  if (fseek(file, 0, SEEK_END) == -1) {
    return -1;
  }

  long size = ftell(file);

  if (fseek(file, 0, SEEK_SET) == -1) {
    return -1;
  }
  return size;
}

char *read_file(const char *file_path) {
  FILE *file = open_file(file_path);
  long file_size = get_file_size(file);

  if (file_size == -1) {
    perror("Error calculating the size of the file.");
    fclose(file);
    return NULL;
  }

  char *source = (char *)malloc((file_size + 1) * sizeof(char));
  if (source == NULL) {
    fclose(file);
    return NULL;
  }

  fread(source, sizeof(char), file_size, file);
  source[file_size] = '\0';
  fclose(file);

  return source;
}

// Verify the extension of the file
int extension_verifier(const char *filename, const char *extension) {
  size_t len_filename = strlen(filename);
  size_t len_ext = strlen(extension);

  if (len_filename >= len_ext &&
      !strcmp(filename + len_filename - len_ext, extension)) {
    return 0;
  }
  return 1;
}
