#include <ErrorHandler.h>

void reportError(int errorcode, int lineno, int column,  const char *msg)
{
  const char *defaultMsg[] = { "lexical error", "syntax error", "comment error" };
  cerr << "Error type" << errorcode << " at line:" << lineno << ": "<< column;
  if (NULL == msg) {
    cerr << defaultMsg[errorcode - 1] << endl;
  }
  else {
    cerr << msg << endl;
  }
}
