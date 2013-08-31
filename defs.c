#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

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
  char * loc_ps = strdup(ps);
  assert(loc_ps);
  return loc_ps;
}
