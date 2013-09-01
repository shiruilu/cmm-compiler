#ifndef DEFS_H
#define DEFS_H

#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef char* string;
typedef unsigned char bool;

/* useful functions */
void * ck_malloc(int len);
string String(const char * ps);
int full_atoi(const char * psnum);
#endif
