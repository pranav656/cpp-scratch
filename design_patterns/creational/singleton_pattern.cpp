
#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <random>
#include <unordered_map>

/*
Creational Design Pattern: They provide various object creation mechanism which increase flexibility and re-use of code
Example use case:
When multiple threads or processes want to log something, this pattern can be used to ensure that the messages don't get mingled and are printed in order.
It can also be used when the object is a physical resource.

Objects that are global by design: something like resource managers.

A good read about how to make Singletons thread safe: https://stackoverflow.com/questions/335369/finding-c-static-initialization-order-problems#335746

*/

class Logger {
   public:
   // static functions can access only static objects
   // This is the only way you can access the Logger object
   // This ensures that no API methods can be called 
   // outside the scope of this object. 
   static Logger& instance() {
       // Some implementations add instantiate the class here
       // However C++03 does not ensure that this 
       // is thread safe.
       return instance_;
   }
   void LogError()
   {
      std::cout<<"Error Logging"<<std::endl;
   }
   private:
   // Private because you don't want to allow creation of objects
   // outside the scope of this class
   Logger() : error_count(0) {}
   ~Logger() {}
   // Delete copy constructor and copy operator
   Logger(const Logger&) = delete;
   Logger& operator=(const Logger&) = delete;
   // static because you can instantiate it only 
   // once
   static Logger instance_;
   std::mutex lock;
   size_t error_count;
};

// Static members can be initialized outside
// the class, not adding this line will lead to a linking error
// This initialization should be in the source file, else everytime a file includes
// the header, this line will be called leading to a linking error
// See: https://stackoverflow.com/questions/185844/how-to-initialize-private-static-members-in-c
Logger Logger::instance_;
// Note about static variables: The lifetime of a static variable starts when the program flow
// first enters the declaration and ends at program termination

int main()
{
   Logger::instance().LogError();
       
    return 0;
}
