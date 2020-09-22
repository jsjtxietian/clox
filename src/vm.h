#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "table.h"

//fix size
//without overflow check
#define STACK_MAX 256

typedef struct
{
	Chunk *chunk;
	//it keeps track of where it is—the location of the instruction currently being executed
	//We use an actual real C pointer right into the middle of the bytecode array instead of something like an integer index because
	//it’s faster to dereference a pointer than look up an element in an array by index.
	uint8_t *ip; // Instruction pointer or PC ; ip points to the instruction about to be executed
	Value stack[STACK_MAX];
	//stackTop points to where the next value to be pushed will go
	Value *stackTop;
	Table strings;
	Obj *objects;
} VM;

//a compiler that reports static errors and a VM that detects runtime errors, the interpreter will use this to know
//how to set the exit code of the process
typedef enum
{
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();

//todo
//To interpret OP_NEGATE, we pop the operand, negate the value, and then push the result.
//That’s a simple implementation, but it increments and decrements stackTop unnecessarily,
//since the stack ends up the same height in the end.
//It might be faster to simply negate the value in place on the stack and leave stackTop alone.

#endif