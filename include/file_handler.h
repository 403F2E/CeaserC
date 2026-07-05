
#ifndef _FILE_OPENER_H
#define _FILE_OPENER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *file);

int extension_verifier(const char *filename, const char *extension);

#endif
