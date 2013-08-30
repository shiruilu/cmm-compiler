#include "ErrorHandler.h"
#include <stdio.h>
#include <assert.h>

void reportError(int errorcode, int lineno, int column,  const char *msg)
{
	assert(1<=errorcode && errorcode<=3);
	const char *defaultMsg[] = { "lexical error", "syntax error", "comment error" };
	fprintf(stderr, "Error type %d at %d:%d ", errorcode, lineno, column);
	if (NULL == msg) {
		fprintf(stderr, "%s\n", defaultMsg[errorcode - 1]);
	}
	else {
		fprintf(stderr, "%s\n", msg);
	}
}
