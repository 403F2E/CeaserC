
#include <stdarg.h>
#include <stdio.h>

#include "../include/core/diagnostic.h"

void diagnostic_error(char *file_path, size_t line, size_t column,
                      const char *fmt, ...) {
  fprintf(stderr, "%s:%zu:%zu: [ERROR] %s\n", file_path, line, column, fmt);
}

void diagnostic_warning(char *file_path, size_t line, size_t column,
                        const char *fmt, ...) {
  fprintf(stderr, "%s:%zu:%zu: [WARNING] %s\n", file_path, line, column, fmt);
}

void diagnostic_note(char *file_path, size_t line, size_t column,
                     const char *fmt, ...) {
  fprintf(stderr, "%s:%zu:%zu: [NOTE] %s\n", file_path, line, column, fmt);
}
