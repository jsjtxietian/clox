#include <stdlib.h>
#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk)
{
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    chunk->lines = NULL;     
    initValueArray(&chunk->constants);
}

// Allocate a new array with more capacity.
// Copy the existing elements from the old array to the new one.
// Store the new capacity.
// Delete the old array.
// Update code to point to the new array.
// Store the element in the new array now that there is room.
// Update the count.
void writeChunk(Chunk *chunk, uint8_t byte, int line)
{
    if (chunk->capacity < chunk->count + 1)
    {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(chunk->code, uint8_t,
                    oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(chunk->lines, int,  
                    oldCapacity, chunk->capacity);     
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
    
}

void freeChunk(Chunk *chunk)
{
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);   
    freeValueArray(&chunk->constants);    
    initChunk(chunk);
}

//returns the index of the constant in the array
int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;        
}     