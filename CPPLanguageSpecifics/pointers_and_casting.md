# Some notes on `void*`
`void *` cannot be dereferenced.
In gcc `sizeof(void)` evaluates to 1 but in other compilers it may not be suppored.
You cannot cast `const* T`, function pointers or volatile pointers to a void. 
Malloc and Calloc return void pointers. In C there is an implicit conversion but in C++ the conversion
has to explcit when you assign it to a specific ptr type.
`void*` are used to create generic functions in C (like a replacement for templates).

# Some notes on casting

`static_cast` : Use it in place of implicit conversion so as to find where casting has been used. Sometimes
it can be difficult to find out implicit conversions. Static cast is more restrictive than C style casts.
Eg. char* to int* is allowed with C style conversion but not with static cast. Static cast won't allow
casting a privately derived child class to the base class. Don't use static cast for down cast, and sometimes 
incompatible classes can be cast with one another (use dynamic casts in these cases). Prefer static cast when 
casting from or to void pointers. 

`dynamic_cast` : Dynamic casts are used when a base classes has multiple child classes and during conversions
a bug could be introduced where the derived class pointers can point to each other (which can cause undefined behavior)
during down casting. When using dynamic cast, if the cast is successful the dynamic cast returns a pointer to the new type,
else a `nullptr` is returned. If the dynamic cast is done to a reference type then it throws a `bad_cast` exception. There is
a performance overhead with using dynamic cast because it check objects at runtime with runtime type information (RTTI). So use it
only when necessary or use `static_cast` instead.
