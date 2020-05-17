main : main.o chunk.o memory.o debug.o value.o
	gcc -Wall -o main memory.o chunk.o debug.o value.o main.o 

chunk.o : memory.h chunk.h common.h 

debug.o : debug.h value.h

memory.o : common.h memory.h 

main.o : chunk.h debug.h common.h 

value.o : value.h common.h

clean :
	rm main main.o debug.o chunk.o memory.o value.o

