# Terminology
The memory model describes how threads interact with computer memory and shared data. Multi-threaded
execution requires the programming language to specify a memory model, without it would not be possible
for programmers, compiler developers to be in synchronization with each other. The memory model 
must define which reorderings are permitted by the compiler, it can define when multiple threads
may access the same memory, specifies when assignments in one thread can be seen in a concurrently
executing thread. Before C++11 there was no memory model defined by the language. The Pthreads model
assumed that the programmer would never create a data race. If the programmer causes data race, then pthread
model specifies undefined memory. The memory model was developed by taking the best ideas from the Java memory model
and the pthreads model

## Ordering
Acquire: Acquiring a resource (updates) or memory making it unavailable to other threads

Release: Releasing a resource or memory making it available to other threads

Acquire_Release: Acquires all updates from other threads + Release updates made to memory

Sequential consistent : Every thread experiences the same total order of all atomic order
of operations.

Relaxed: Safe from torn read/writes. safe from clobbered updates, no synchronization
