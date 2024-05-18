# Compilation to Byte Code in GCC
## Pre processing
Run the preprocessor using the command: `g++ -E source.cpp -o source.i`
Macro expansion, file inclusion, confitional compilation. The results is stored in source.i

## Compilation
Command: `g++ -S source.i -o source.s`

Parsing: The pre-processed code is parsed to create an Abstract Syntax Tree (AST).

Semantic Analysis: Type checks and symbol resolution are performed.

Intermediate code Generation : The compiler generates an intermediate representation (IR) of the code.

Optimization: Various optimizations are applied to the IR

Assembly Generation : The optimized IR is translated to assembly language. 

The assembly file `source.s` is generated.

## Assembly
Command : `g++ -c source.s -o source.o`
The assembler translates the assembly code into machine code.
The object file `source.o` is generated, containing the machine code and data.

## Linking:
Command : `g++ source.o -o executable`
The linker combines `source.o` with necessary standard libraries. External references like `std::cout` are resolved.
The executable file `executable` is generated and ready to run. 
