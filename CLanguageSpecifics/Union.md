# Notes on Union

Union is a user defined data type. Members of the union share the same 
memory location. It is used to obtain polymorphism in C.

```c++
union u {
int x;
shorty y;
char z;
}
```
In the example above, the union has 4 bytes allocated (size of int, biggest data) and all three point to this
memory location. Unions are used in resource constrained systems where you cannot have big structures. 
In some cases, union is also use to enable byte level access like shown below:

```c++

union u {
char bytes[4];
int val;
};
```

You could access the byte level data of val using the bytes array. 
