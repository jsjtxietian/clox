#ifndef clox_table_h
#define clox_table_h

#include "common.h"
#include "value.h"

typedef struct
{
    ObjString *key;
    Value value;
} Entry;

typedef struct
{
    //it’s the number of entries plus tombstones.
    int count;
    //the allocated size of the array
    int capacity;
    Entry *entries;
} Table;

void initTable(Table *table);
void freeTable(Table *table);
//If it finds an entry with that key, it returns true,
//otherwise it returns false. If the entry exists, it stores the resulting value in the value output parameter.
bool tableGet(Table *table, ObjString *key, Value *value);
bool tableSet(Table *table, ObjString *key, Value value);
bool tableDelete(Table *table, ObjString *key);
//copy all of the entries of one hash table into another:
void tableAddAll(Table *from, Table *to);
ObjString *tableFindString(Table *table, const char *chars, int length,
                           uint32_t hash);

#endif