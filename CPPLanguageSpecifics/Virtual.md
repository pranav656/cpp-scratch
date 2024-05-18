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
