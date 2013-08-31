#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

#define TEST_DEFS_DEBUG

void * ck_malloc(int len)
{
  void *p = malloc(len);
  assert(p);
  return p;
}
/*
  usage : string xx = String("xxyyzz");
 */
string String(char * ps)
{
  //char * loc_ps = (char *)malloc(sizeof(ps));
  //strcpy(loc_ps, ps);
  char * loc_ps = strdup(ps);
  assert(loc_ps);
#ifdef TEST_DEFS_DEBUG
  fprintf(stdout, "ps len : %d\n", strlen(ps));
  fprintf(stdout, "loc_ps len : %d\n", strlen(loc_ps));
#endif
  return loc_ps;
}
