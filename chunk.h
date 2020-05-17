// a module to define our code representation

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h" 

// a one-byte operation code (universally shortened to “opcode”).
typedef enum
{
	OP_CONSTANT,
	OP_RETURN, //return from the current function

} OpCode;

typedef struct
{
	// the number of elements in the array we have allocated (“capacity”) and 
	//how many of those allocated entries are actually in use (“count”).
	int count;
	int capacity;
	uint8_t *code;
	int* lines; //line info
	ValueArray constants;
} Chunk;


void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);     
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value); 

#endif