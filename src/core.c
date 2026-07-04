#include "../include/core/core.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_malloc(size_t size) {
  void *buf = malloc(size);
  if (!buf) {
    fprintf(stderr, "[Error] failed to allocate %lu bytes.: %s\n", size,
            strerror(errno));
    return NULL;
  }
  return buf;
}

void *_realloc(void *ptr, size_t size) {
  void *buf = realloc(ptr, size);
  if (!buf) {
    fprintf(stderr, "[Error] failed to reallocate %lu bytes.: %s\n", size,
            strerror(errno));
    return NULL;
  }
  return buf;
}
