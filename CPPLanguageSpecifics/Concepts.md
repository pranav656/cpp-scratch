
References:
[C++ 20 concepts video](https://www.youtube.com/watch?v=stsBt5L1_XE&t=2s)

```c++
// The compiler does not check if NUM is really a number and the
// user can pass any type they want
// Concepts enable constraints on templates
template<typename NUM>
NUM sum(NUM a, NUM b)
```



```c++
// Concept returns true
template<typename T>
concept Number = std::is_same_v<std::remove_cv_t<T>, int> || std::floating_point<T>;

// Perform compile time
// checking of concepts
static_assert(Number<int>);
static_assert(Number<float>);
static_assert(Number<double>);
static_assert(Number<std::string> == false);

// evaluates to false without std::remove_cv_t
static_assert(Number<const int>)

// this fails during compilation
static_assert(Number<unsigned int>)
```


```c++
// You could fix the unsigned int
// by checking if the type is convertible to double
template<typename T, typename TARGET_TYPE>
concept convertible_to = std::is_convertible_v<TARGET_TYPE, T>

template<convertible_to<double> T>
T sum(T a, T b);

```

You could also use `is_arithmetic` type traits to enforce that
numbers are passed to the sum function

```c++

template<typename T> requires std::is_arithmetic<T>
T sum(T a, T b)
{
	return a +b;
}

```

With concepts and requires keywords:
```c++
#include <concepts>
#include <type_traits>
#include <iterator>
#include <vector>

template<typename T>
concept Summable = requires (T a, T b) {
    {a + b} -> std::same_as<T>;
};

auto sum(Summable auto a, Summable auto b)
{
    return a + b;
}
int main()
{
   sum(1, 2);
   // fails with a nice compilation message
   sum(std::vector<int>{}, std::vector<int>{});
   return 0;
}
```


```c++
template<typename T>
concept Summable = requires (T a, T b) {
    {a + b} -> std::same_as<T>;
};
```

