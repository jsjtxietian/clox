main : main.o chunk.o memory.o debug.o 
	gcc -Wall -o main memory.o chunk.o debug.o main.o 

chunk.o : memory.h chunk.h common.h 

debug.o : debug.h

memory.o : common.h memory.h 

main.o : chunk.h debug.h common.h 

