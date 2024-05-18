## Example program explaining vtable

```
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }

    virtual void display() {
        std::cout << "Base class display function" << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base class destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }

    void display() override {
        std::cout << "Derived class display function" << std::endl;
    }

    ~Derived() override {
        std::cout << "Derived class destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show();    // Calls Derived's show function
    b->display(); // Calls Derived's display function
    delete b;     // Calls Derived's destructor followed by Base's destructor

    return 0;
}


```

## Vtable layout and mapping
Base class vtable contains pointers to `Base::show`, `Base::display`, `Base::~Base`.
Derived class vtable contains pointers to `Derived::show`, `Derived::display`, `Derived::~Derived`.

When an object of `Derived` class is creates it contains pointer `vptr` that points to `Derived` class vtable. When 
a funvtion call is made through a base class pointer, the vtable is used to dynamically bind the correct function.

```
+----------------------------------+
| Base vtable                      |
+----------------------------------+
| &Base::show                      |
| &Base::display                   |
| &Base::~Base                     |
+----------------------------------+

+----------------------------------+
| Derived vtable                   |
+----------------------------------+
| &Derived::show                   |
| &Derived::display                |
| &Derived::~Derived               |
+----------------------------------+

+--------------------------+
| Derived object           |
+--------------------------+
| vptr (points to Derived  |
| vtable)                  |
+--------------------------+
| other member variables   |
+--------------------------+

```
## function call mechanism
Object Creation: When `Derived` object is created, it's `vptr` is set to point to `Derived` class vtable.

Function call: When `b->show` is called, the program looks up the `vptr` in the `Derived` object, finds the `Derived`
class vtable and calls the function pointed to by the first entry (`&Derived::show`)

Destructor call: When `delete b` is called, the destructor is called through the vtable. The program
looks up the `vptr` and calls the function pointed by the destructor entry in the `Derived` class vtable followed
by the base class destructor.

Here's the step-by-step execution of the provided code:

`Base* b = new Derived();:`
A Derived object is created.
vptr of the Derived object is set to the Derived class vtable.

`b->show();`:
b is of type Base*, but points to a Derived object.
The vptr points to the Derived vtable.
The program calls Derived::show().

`b->display();`:
The vptr points to the Derived vtable.
The program calls Derived::display().

`delete b;`:
The vptr points to the Derived vtable.
The program calls Derived::~Derived(), followed by Base::~Base().

By understanding the vtable and vptr mechanism, we see how C++ achieves dynamic polymorphism, enabling the correct function implementations to be called based on the actual object type at runtime.

The vtable (virtual table) lookup in C++ is a constant time operation, typically O(1). Here’s why and how it works:

### Vtable and Vptr Overview

1. **Vtable**:
    - Each class with virtual functions has a vtable, a static array of function pointers.
    - The vtable is created by the compiler and is shared among all instances of the class.

2. **Vptr**:
    - Each object of a class with virtual functions contains a vptr (virtual table pointer).
    - The vptr points to the vtable of the class to which the object belongs.

### How Vtable Lookup Works

When a virtual function is called on an object through a base class pointer or reference:

1. **Dereference Vptr**:
    - The compiler generates code to access the vptr from the object. This is a simple pointer dereference.

2. **Access Vtable**:
    - The vptr points to the vtable, which is an array of function pointers.

3. **Index into Vtable**:
    - The index of the function in the vtable is determined at compile time based on the order of the virtual functions in the class.
    - The specific function pointer is accessed by indexing into the vtable.

4. **Call the Function**:
    - The function pointer is dereferenced, and the function is called.

### Constant Time Lookup

- **Pointer Dereference**:
    - Accessing the vptr and then the vtable involves two pointer dereferences, both of which are O(1) operations.

- **Array Indexing**:
    - Indexing into the vtable is also an O(1) operation since array access by index is a constant time operation.

### Example

Consider the following example to illustrate:

```cpp
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }
    virtual void display() {
        std::cout << "Base display" << std::endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show" << std::endl;
    }
    void display() override {
        std::cout << "Derived display" << std::endl;
    }
    ~Derived() override {}
};

int main() {
    Base* b = new Derived();
    b->show();    // Calls Derived::show
    b->display(); // Calls Derived::display
    delete b;
    return 0;
}
```

```
Base vtable:
+-------------------------+
| &Base::show             |  // Index 0
| &Base::display          |  // Index 1
+-------------------------+

Derived vtable:
+-------------------------+
| &Derived::show          |  // Index 0
| &Derived::display       |  // Index 1
+-------------------------+
```

```
Derived object:
+--------------------------+
| vptr (points to Derived  |
| vtable)                  |
+--------------------------+
| other member variables   |
+--------------------------+
```
Each step (dereferencing the vptr, accessing the vtable, and indexing into the vtable) is an O(1) operation.
Therefore, the entire lookup process to call a virtual function is O(1). 

Vtable lookup in C++ is a constant time operation due to the fixed steps involved (pointer dereference and array indexing), making it efficient for supporting runtime polymorphism. This design ensures that virtual function calls have predictable and consistent performance characteristics.
