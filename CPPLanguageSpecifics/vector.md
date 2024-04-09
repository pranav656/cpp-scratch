# Difference between push back and emplace back
[StackOverflow](https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back)
The real C++0x form of emplace_back is really useful: void emplace_back(Args&&...);
Instead of taking a value_type, it takes a variadic list of arguments, so that means that you can now perfectly forward the arguments and construct directly an object into a container without a temporary at all.
That's useful because no matter how much cleverness RVO and move semantics bring to the table, there are still complicated cases where a push_back is likely to make unnecessary copies (or move).
