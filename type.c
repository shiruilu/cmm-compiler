#include "type.h"

bool is_same_type(Type *a, Type *b) {
    if (a->kind != b->kind)
        return FALSE;
    if (a->kind == Basic)
        return a->u.basic == b->u.basic;
    else if (a->kind == Array)
        return is_same_type(a->u.array.elem, b->u.array.elem);
    else { //Structure
        FieldList *a_field = a->u.structure, *b_field = b->u.structure;
        while (a_field && b_field) {
            if (!is_same_type(a_field->type, b_field->type))
                return FALSE;
            a_field = a_field->next;
            b_field = b_field->next;
        }
        if (a_field || b_field)
            return FALSE;
        return TRUE;
    }
}