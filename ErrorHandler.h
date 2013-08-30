#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <iostream>
using namespace std;

void reportError(int errorcode, int lineno, int column, const char* msg);

#endif
