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

Tuple can store muliple data types.

```c++
// template function to return type based on compile time conditions
template<bool condition, typename THEN, typename ELSE>
struct if_;

template<typename THEN, typename ELSE>
struct if_<true, THEN, ELSE>{
  using type = THEN;
};

template<typename THEN, typename ELSE>
struct if_<false, THEN, ELSE>{
  using type = ELSE;
};

// template function to check if a type is present in
// a tuple
// template function to check if a type is present in
// a tuple
template<typename SEARCH, typename TUPLE, size_t start_from=0>
struct contains_type :
  if_<
        std::is_same<std::tuple_element_t<start_from, TUPLE>, SEARCH>::value,
        std::true_type,
        typename if_<
            (start_from == std::tuple_size<TUPLE>::value - 1),
            std::false_type,
            contains_type<SEARCH, TUPLE, start_from+1>
            >::type
        >::type
{};

// corner case for empty tuple search
template<typename SEARCH>
struct contains_type <SEARCH, std::tuple<>, 0> : std::false_type{};

std::tuple<int, float, double> t;
std::tuple<> t2;

// evaluates to true
std::cout<<std::boolalpha<<contains_type<double, decltype(t)>::value <<std::endl;

// evaluates to false
std::cout<<std::boolalpha<<contains_type<char, decltype(t)>::value <<std::endl;

// evaluates to false
std::cout<<std::boolalpha<<contains_type<char, decltype(t2)>::value <<std::endl;

```

# Example on variadic templates

```c++
void printn()
{
    std::cout<< " " <<std::endl;    
}

template<typename LAST>
void printn(LAST&& t)
{
    std::cout<< std::forward<LAST>(t) <<std::endl;
}

template<typename T0, typename ...T1toN>
void printn(T0&& t, T1toN... rest){
    std::cout<< std::forward<T0>(t) <<" ";
    printn(std::forward<T1toN>(rest)...);
}

template<typename TUPLE, std::size_t ... indices>
void print_tuple_impl(TUPLE &&t, std::index_sequence<indices...>) {
    printn(std::get<indices>(std::forward<TUPLE>(t))...);
}

// Template metafunction to print tuples
template<typename TUPLE>
void print_tuple(TUPLE&& t){
    // index sequence makes a series of indices that can be used by the 
    // implementation 
    print_tuple_impl(std::forward<TUPLE>(t), std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
}

```

