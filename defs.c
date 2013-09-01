#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

// #define TEST_DEFS_DEBUG

/*
 * checked malloc, assert will report memory allocation error
 */
void * ck_malloc(int len)
{
	void *p = malloc(len);
	assert(p);
	return p;
}

/*
 * usage : string xx = String("xxyyzz");
 */
string String(const char * ps)
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

/*
 * radix atoi, add radix support to atoi
 * called by: full_atoi()
 */
int radix_atoi(const char *psnum, int radix)
{
	// assert(*psnum); // psnum not null string
	int val = 0;
	int digit;
	for( ; '\0'!= *psnum; ++psnum) {
		if(*psnum >= 'a')
			digit = 10 + *psnum - 'a';
		else if(*psnum >= 'A')
			digit = 10 + *psnum - 'A';
		else
			digit = *psnum - '0';
		val = val * radix + digit;
	}

	return val;
}

/*
 * full atoi, judge radix and translate to int
 */
int full_atoi(const char *psnum)
{
	assert(psnum && *psnum); // psnum not null pointer && not null string
	if('0' == *psnum) {
		if('x'==*(psnum +1) || 'X'==*(psnum+1)) {
			return radix_atoi(psnum+2, 16);
		}
		else {
			return radix_atoi(psnum+1, 8);
		}
	}
	else {
		return radix_atoi(psnum, 10);
	}
}
