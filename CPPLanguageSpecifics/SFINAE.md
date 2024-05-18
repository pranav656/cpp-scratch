```
#include <iostream>
#include <complex>
#include <functional>

using namespace std;

// returns true if t*t is valid
// Helper template to check if a type supports the multiplication operator
template<typename T, typename = void>
struct has_multiplication_operator : std::false_type {};

template<typename T>
struct has_multiplication_operator<T, std::void_t<decltype(std::declval<T>() * std::declval<T>())>> : std::true_type {};

class A {
public:
A(int _a)
{
    a = _a;
}
int operator* (const A& other) const
{
    return a * other.a;
}
private:
    int a;
};

int main()
{
   
    if constexpr(has_multiplication_operator<A>::value) {
         A a1(1), a2(2);
        cout<<"supports multiplication operator:"<<a1*a2;
    }
    else
    {
        cout<<"does not support multiplication operator";
    }
    return 0;
}

````
