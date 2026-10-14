### Tool chain
-[x] CMake
-[x] C++ 17+
-[] SDL2 for display and input (Downloaded)
-[] doctest for opcode tests (Downloaded)

14/10/26 10:30 - Created interface printing, registry structure, memory pool. Chose a variable type. To continue: Finish the interface, test printing. Create rails for testing with doctest. Finish Memory and test memory manipulation and addresses, test the stack and timers.

14/10/26 12:37 - Working on creating a decoder for the instruction. Changed the input for the instruction variables to a hex number without the use of character arrays

Exercise to illustrate the decoding of an instruction:

HEX: 0xD123
nnn: 123
n: 3
x: 1
y: 2
kk: 23
