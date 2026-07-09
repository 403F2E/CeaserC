
#include <stdarg.h>
#include <stdio.h>

#include "../include/core/diagnostic.h"

void diagnostic_error(char *file_path, size_t line, size_t column,
                      const char *fmt, ...) {
  fprintf(stderr, "%s:%zu:%zu:" DIAG_ERROR_COLOR " [ERROR] " ANSI_RESET "%s\n",
          file_path, line, column, fmt);
}

void diagnostic_warning(char *file_path, size_t line, size_t column,
                        const char *fmt, ...) {
  fprintf(stderr,
          "%s:%zu:%zu:" DIAG_WARNING_COLOR " [WARNING] " ANSI_RESET "%s\n",
          file_path, line, column, fmt);
}

void diagnostic_note(char *file_path, size_t line, size_t column,
                     const char *fmt, ...) {
  fprintf(stderr, "%s:%zu:%zu:" DIAG_NOTE_COLOR " [NOTE] " ANSI_RESET "%s\n",
          file_path, line, column, fmt);
}
