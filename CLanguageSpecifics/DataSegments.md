# Notes on data segments
The memory layout in a compiled C program has six parts: text segment, initialized data segment, uninitialized data segment, command line arguments, stack, heap.
Non const global/static variables are stored in read-write part of intialized data segment if the variables are initialized.  Uninitilized variables are
stored in the uninitialized data segment. Local variables, arguments of functions are stored in the stack. 
Dynamically allocated memory is stored in the heap (memory created with malloc, calloc, etc.)
