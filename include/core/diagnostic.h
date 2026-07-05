
#ifndef _DIAGNOSTIC_H
#define _DIAGNOSTIC_H

#include <stddef.h>

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
