
#ifndef _FILE_OPENER_H
#define _FILE_OPENER_H

#include <stdio.h>

char *read_file(const char *file);

int extension_verifier(const char *filename, const char *extension);

#endif
