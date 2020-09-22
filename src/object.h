#ifndef clox_object_h
#define clox_object_h

#include "common.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)

#define IS_STRING(value) isObjType(value, OBJ_STRING)

#define AS_STRING(value) ((ObjString *)AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString *)AS_OBJ(value))->chars)

typedef enum
{
    OBJ_STRING,
} ObjType;

struct sObj
{
    ObjType type;
    struct sObj* next;
};

//Given an ObjString*, you can safely cast it to Obj* and then
//access the type field from it.
struct sObjString
{
    Obj obj;
    int length;
    char *chars;
    uint32_t hash;
};

ObjString* copyString(const char* chars, int length);
ObjString* takeString(char* chars, int length);
void printObject(Value value);

//A macro is expanded by inserting the argument expression every place
//Do not put the body of this function right in the macro
//the parameter name appears in the body. If a macro uses a
//parameter more than once, that expression gets evaluated multiple times.
//That’s bad if the expression has side effects.
static inline bool isObjType(Value value, ObjType type)
{
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

#endif