# Terminology
The memory model describes how threads interact with computer memory and shared data. Multi-threaded
execution requires the programming language to specify a memory model, without it would not be possible
for programmers, compiler developers to be in synchronization with each other. It's a set of rules so
that the programmers don't have to think about the hardware (a kind of contract).
The memory model 
must define which reorderings are permitted by the compiler, it can define when multiple threads
may access the same memory, specifies when assignments in one thread can be seen in a concurrently
executing thread. Before C++11 there was no memory model defined by the language. The Pthreads model
assumed that the programmer would never create a data race. If the programmer causes data race, then pthread
model specifies undefined behavior. The memory model was developed by taking the best ideas from the Java memory model
and the pthreads model. 

## Ordering
Acquire: Acquiring a resource (updates) or memory making it unavailable to other threads

Release: Releasing a resource or memory making it available to other threads

Acquire_Release: Acquires all updates from other threads + Release updates made to memory

Sequential consistent : Every thread experiences the same total order of all atomic order
of operations.

Relaxed: Safe from torn read/writes. safe from clobbered updates, no synchronization

# Notes from talk C++11/14/17 atomics and memory model:
[Video link](https://www.youtube.com/watch?v=DS2m7T6NKZQ&t=3s)


C++ Memory model goal: Maximize performance but still maintain portability

Iron Triangle of Parallel Programming: Performance, General Portability and Productivity

The code snippet below is a bit faster on some platforms:
```c++
int x = 0;
atomic<int> y = 0;
//Thread 1
x = 17;
y.store(1, memory_order_release)

//Thread 2
while(y.load(memory_order_acquire) != 1)
assert(x==17);
```

than 
```c++
int x = 0;
atomic<int> y = 0;

while(y != 1)
  continue;
assert(x==17);
```

```c++
//Thread 1
atomic_store_explicit(&a, 3, memory_order_release)

// Thread 2 acquires writes from thread 1

//Thread 2
i = atomic_load_explicit(&a, memory_order_acquire)


```
Sequentially consistent: What is observed is consistent with a sequential ordering of 
all events in the system.

If a program has a race it has undefined behavior.



