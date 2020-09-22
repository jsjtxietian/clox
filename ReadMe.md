# A BYTECODE VIRTUAL MACHINE

#### TODO
* Our encoding of line information is hilariously wasteful of memory. Given that a series of instructions often correspond to the same source line, a natural solution is something akin to run-length encoding of the line numbers.Devise an encoding that compresses the line information for a series of instructions on the same line. Change writeChunk() to write this compressed form, and implement a getLine() function that, given the index of an instruction, determines the line where the instruction occurs.
* Because OP_CONSTANT only uses a single byte for its operand, a chunk may only contain up to 256 different constants. That’s small enough that people writing real-world code will hit that limit. We could use two or more bytes to store the operand, but that makes every constant instruction take up more space. Most chunks won’t need that many unique constants, so that wastes space and sacrifices some locality in the common case to support the rare case. To balance those two competing aims, many instruction sets feature multiple instructions that perform the same operation but with operands of different sizes. Leave our existing one-byte OP_CONSTANT instruction alone, and define a second OP_CONSTANT_LONG instruction. It stores the operand as a 24-bit number, which should be plenty. It adds value to chunk’s constant array and then writes an appropriate instruction to load the constant. Also add support to the disassembler for OP_CONSTANT_LONG instructions.
    ```
    void writeConstant(Chunk* chunk, Value value, int line) {
    // Implement me...
    }
    ```
* Implement reallocate() without calling realloc(), malloc(), or free().
* Our VM’s stack has a fixed size, and we don’t check if pushing a value overflows it. This means the wrong series of instructions could cause our interpreter to crash or go into undefined behavior. Avoid that by dynamically growing the stack as needed.
* To interpret OP_NEGATE, we pop the operand, negate the value, and then push the result. That’s a simple implementation, but it increments and decrements stackTop unnecessarily, since the stack ends up the same height in the end. It might be faster to simply negate the value in place on the stack and leave stackTop alone. Try that and see if you can measure a performance difference.
* Support string interpolation.
* Add support for :? to the compiler. 
* Each string requires two separate dynamic allocations—one for the ObjString and a second for the character array. Accessing the characters from a value requires two pointer indirections, which can be bad for performance. A more efficient solution relies on a technique called “flexible array members”. Use that to store the ObjString and its character array in a single contiguous allocation.
* We could keep track of which ObjStrings own their character array and which are “constant strings” that just point back to the original source string or some other non-freeable location. Add support for this.


####  Test Cases
* todo

### Additional Info
#### Pratt parsers
* http://journal.stuffwithstuff.com/2011/03/19/pratt-parsers-expression-parsing-made-easy/
* https://matklad.github.io/2020/04/13/simple-but-powerful-pratt-parsing.html