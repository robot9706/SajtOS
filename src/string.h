#ifndef __STRING__
#define __STRING__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t strlen(const char* str);
bool strcomp(const char* a, const char* b);

#endif