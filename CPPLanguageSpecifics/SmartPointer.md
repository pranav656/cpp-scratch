# unique_ptr
Preferred way to make a unique pointer is using `make_unique` due to exception safety. See answer [here](https://stackoverflow.com/questions/19472550/exception-safety-and-make-unique).
Copy constructor and copy assignment operator of a unique pointer are deleted. 

# shared_ptr
Uses reference counting, keeping track of multiple references to your pointer. make_shared is used not for exception safety but for efficieny (to prevent multiple allocations, control block + memory in one go). 


# weak_ptr
When assigning shared pointer to a weak pointer, it does not increase the reference counter. One use-case is that it can be used to check if a pointer is still alive. 
