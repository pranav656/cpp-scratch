
#include <bits/stdc++.h>
/*
This is a try of the Policy Based design mentioned in the 
book Hands on Design Patterns with C++ by Fidor Pikus.
This is an example of a strategy based pattern that can
be implemented with templates.
An example of how to design a custom smart pointer 
class is shown as an example of policy based design
*/

using namespace std;

// Below is the implementation of the Basic Smart pointer.
// A drawback is that this type of smart pointer requires
// the type to have a delete operator. The implementation constrains
// the objects it can own to the onwes which were created with new 
// and delete. It also does not work with multiple objects at a time.
// This is where a Policy based strategy would help, with a different
// delete policy for different types of objets.
template <typename T>
class BasicSmartPtr
{
public:
    // To avoid implicit conversions
    explicit BasicSmartPtr(T* p = nullptr) : p_(p) {}
    T* operator->() {return p_;}
    const T* operator->() const {return *p_;}
    T& operator*() {return *p_;}
    const T& operator*() const{return *p_;}
    ~BasicSmartPtr(){
        // delete pointer 
        cout<<"Destructing instance of BasicSmartPtr"<<endl;
        delete p_;
    }
private:
    T *p_;
    // Dont allow Copy construction or assignemnt
    BasicSmartPtr(const BasicSmartPtr&) = delete;
    BasicSmartPtr& operator=(const BasicSmartPtr&) = delete;
};


// The implementation policy below takes a
// deletion policy as a template and uses the 
// callable object of the delection policy to 
// release the memory. The deletion policy 
// can be modified according to your needs
template <typename T, typename DeletionPolicy>
class SmartPtrWithDeletePolicy
{
public:
    explicit SmartPtrWithDeletePolicy(T* p = nullptr, const DeletionPolicy& deletion_policy = DeletionPolicy())
    : p_(p), deletion_policy_(deletion_policy) {}
    T* operator->() {return p_;}
    const T* operator->() const {return *p_;}
    T& operator*() {return *p_;}
    const T& operator*() const{return *p_;}
    ~SmartPtrWithDeletePolicy() {
        cout<<"Deleting pointer with deletion policy"<<endl;
        deletion_policy_(p_);
    }
private:
    T* p_;
    DeletionPolicy deletion_policy_;
    // Dont allow Copy construction or assignemnt
    SmartPtrWithDeletePolicy(const SmartPtrWithDeletePolicy&) = delete;
    SmartPtrWithDeletePolicy& operator=(const SmartPtrWithDeletePolicy&) = delete;
};

template <typename T>
struct DeleteByOperator {
    void operator()(T*p) const {
        delete p;
    }
};

int main() {
   BasicSmartPtr ptr(new int(5));
   SmartPtrWithDeletePolicy<int, DeleteByOperator<int>> ptr2(new int(6));
}
