#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#define MAX_ERRINFO 40
/* ErrorCode starts at 1 */
typedef enum {LEXICAL_ERROR = 1, SYNTAX_ERROR, COMMENT_ERROR} ErrorCode;

void reportError(int errorcode, int lineno, int column, const char* msg);

#endif
