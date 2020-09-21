#ifndef clox_memory_h
#define clox_memory_h

#include <stdlib.h>

//it scales based on the old size. We grow by a factor of two, which is pretty typical.
//1.5× is another common choice.
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

#define GROW_ARRAY(previous, type, oldCount, count) (type *)reallocate(previous, sizeof(type) * (oldCount), sizeof(type) * (count))

#define FREE_ARRAY(type, pointer, oldCount) reallocate(pointer, sizeof(type) * (oldCount), 0)

//we’ll use for all dynamic memory management in clox—allocating memory, freeing it,
//and changing the size of an existing allocation. Routing all of those operations
//through a single function will be important later when we add a garbage collector
//that needs to keep track of how much memory is in use.
//oldSize	newSize	                Operation
//0	        Non‑zero	            Allocate new block.
//Non‑zero	0	                    Free allocation.
//Non‑zero	Smaller than oldSize	Shrink existing allocation.
//Non‑zero	Larger than oldSize	    Grow existing allocation.
void *reallocate(void *previous, size_t oldSize, size_t newSize);

#endif