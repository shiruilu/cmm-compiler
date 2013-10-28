#ifndef _TYPE_H_
#define _TYPE_H_

/* Definations */
typedef struct FieldList_ {
    string name;
    Type type;
    struct FiledList * next;
}FieldList;

typedef struct Type_ {
    enum {basic, array, structure} kind;
    union {
        struct { struct Type_ elem; unsigned int size } array;
        FieldList structure;
    }u;
}Type;

#endif