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

`reinterpret_cast` : It can convert any pointer to another pointer. So it can be dangerous if you don't know what you are doing.
It can be helpful in situations where you understand the memory allocation of the objects and you understand the behavior. Also note
that this can make the code not portable between platform as the memory allocations may vary from platform to platform.

`const_cast` : This cast can be used to change the constant or volatile qualifiers of pointers or references. Only a pointer, 
a reference or a pointer to member type can be converted using `const_cast`. It removes the constness of your variable. If you try
to reassign a variable which was declared as const orginally by using const_cast you  might get undefined behavior. You can 
modify objects which were not const in the first place but were referred to with const pointer with const_cast, that should not
have any impact. You can use const cast when you have to pass const objects which are not modified to functions which take
non const arguments as parameters. 
