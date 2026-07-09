
#ifndef _DIAGNOSTIC_H
#define _DIAGNOSTIC_H

#include <stddef.h>

#define ANSI_RESET "\033[0m"

#define ANSI_RED_BOLD "\033[1;31m"
#define ANSI_YELLOW_BOLD "\033[1;33m"
#define ANSI_BLUE_BOLD "\033[1;34m"
#define ANSI_CYAN_BOLD "\033[1;36m"

#define DIAG_ERROR_COLOR ANSI_RED_BOLD
#define DIAG_WARNING_COLOR ANSI_YELLOW_BOLD
#define DIAG_NOTE_COLOR ANSI_CYAN_BOLD

enum DIAGNOSTIC_SEVERITY { DIAG_ERROR, DIAG_WARNING, DIAG_NOTE };

struct Diagnostic {
  enum DIAGNOSTIC_SEVERITY severity;

  char *message;

  size_t line;
  size_t column;
};

void diagnostic_error(char *, size_t, size_t, const char *, ...);

void diagnostic_warning(char *, size_t, size_t, const char *, ...);

void diagnostic_note(char *, size_t, size_t, const char *, ...);

#endif
