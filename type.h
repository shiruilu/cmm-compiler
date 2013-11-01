#ifndef _TYPE_H_
#define _TYPE_H_

#include "defs.h"

typedef enum {Char, Int, Float} basic_type;
typedef struct FieldList_ FieldList;
typedef struct Type_ Type;

/* Definations */
struct FieldList_ {
    string id;
    int lineno;
    Type * type;
    FieldList * next;
};

struct Type_ {
    enum {Basic, Array, Structure} kind;
    union {
        basic_type basic;
        struct { Type * elem; unsigned int size } array;
        FieldList * structure;
    } u;
};

typedef struct arg_node_ {
    Type * type;
    struct arg_node_ * next;
} arg_node;

bool is_same_type(Type *a, Type *b);

#endif