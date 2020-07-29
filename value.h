#ifndef clox_value_h 
#define clox_value_h 

#include "common.h"  

typedef double Value;

//Each chunk will carry with it a list of the values that appear as literals in the program. 
//For example, the Java Virtual Machine associates a constant pool with each compiled class. 
typedef struct {     
    int capacity;      
    int count;         
    Value* values;     
} ValueArray;      

void initValueArray(ValueArray* array);              
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);   

void printValue(Value value);     

#endif    