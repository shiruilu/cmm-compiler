#include "ErrorHandler.h"
#include "defs.h"
#include <stdio.h>

// #ifdef PRINT_AST
bool gl_error_exist = FALSE;
// #endif

void reportError(int errorcode, int lineno, int column,  const char *msg)
{
	assert(1<=errorcode);
	gl_error_exist = TRUE;

	const char *defaultMsg[] = { "lexical error", "syntax error", "comment error" };
	fprintf(stderr, "Error type %d at line:%d ", errorcode, lineno);
	if (NULL == msg) {
		fprintf(stderr, "%s\n", defaultMsg[errorcode - 1]);
	}
	else {
		fprintf(stderr, "%s\n", msg);
	}
}

