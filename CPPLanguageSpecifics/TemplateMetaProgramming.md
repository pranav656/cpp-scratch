# Notes from [playlist](https://www.youtube.com/watch?v=VBI6TSo8Zog&list=PLWxziGKTUvQFIsbbFcTZz7jOT4TMGnZBh)

You can use type traits to find the trait of a type during compile time. You can check if a type is a pointer with the 
following piece of code
```c++
if constexpr(std::is_pointer<T>::value> {
// perform action with pointer type
}
```

You can make your own type trait for checking if a type is pointer

```c++
template<typename T>
struct is_pointer {
// static so you can use the
// value without instantiatng the struct
// constexpr, so that you can use it
// at compile time
static constexpr bool value = false;
}

// partial specialization for pointer types
template<typename T*>
struct is_pointer {
static constexpr bool value = true;
}

// class template to strip
// pointer type of it's pointer 
template<typename T>
struct strip_pointer {
  using type = T;
};


template<typename T*>
struct strip_pointer {
  using type = T;
};

```

Note: cv variant means const volatile variants
