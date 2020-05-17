// a module to define our code representation

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// a one-byte operation code (universally shortened to “opcode”).
typedef enum
{
	OP_RETURN, //return from the current function

} OpCode;

typedef struct
{
	// the number of elements in the array we have allocated (“capacity”) and 
	//how many of those allocated entries are actually in use (“count”).
	int count;
	int capacity;
	uint8_t *code;
} Chunk;


void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);     
void writeChunk(Chunk* chunk, uint8_t byte);

#endif