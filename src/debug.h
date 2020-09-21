#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

//An assembler is an old-school program that takes a file containing
//human-readable mnemonic names for CPU instructions like “ADD” and
//“MULT” and translates them to their binary machine code equivalent.
//A dis-assembler goes in the other direction—given a blob of machine code, it spits out a textual listing of the instructions.
void disassembleChunk(Chunk *chunk, const char *name);
int disassembleInstruction(Chunk *chunk, int offset);

#endif