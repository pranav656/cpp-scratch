
#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <list>
#include <cmath>
#include <cassert>
#include <vector>
#include <random>
#include <unordered_map>

/*
Create a ISBN cache, the least recently used entry should be removed when the cache 
is full.

Straightforward Approach:
Create a hashmap with all the entries, keep a count of how many times the 
element was accessed in a counter. When the cache is full iterate over the array
to find the least count. When the hashmap is not full the time complexity is
O(1), however when it is full searching for the least recently used 
can take upto O(n).

Optimized approach:
One idea is to keep a queue of recently used elements. When a element is inserted or read, you bump the accessed element to the top
of the queue. The queue is implemented as a linked list. The hashmap also contains
a iterator to the element which corresponds to the element. In this case,
the time complexity is O(1) at the cost of additional memory complexity O(n)
which is the size of the queue. 
*/

class ISBNCache {
   // should be private, but public for the sake of
   // testing implementation quickly
   public:
      std::unordered_map<int, std::pair<std::list<int>::iterator, int>> elements;
      std::list<int> queue;
      int c_size;
      auto move_to_front(std::list<int>::iterator it)
      {
          int val = *it;
          queue.erase(it);
          queue.push_front(val);
          return queue.begin();
      }
   public:
      void insert(int isbn, int price)
      {
          auto it = elements.find(isbn);
          if(it != elements.end())
          {
              auto new_it = move_to_front((it->second).first);
              elements[isbn] = std::make_pair(new_it, isbn);
          }
          else
          {
              queue.push_front(isbn);
              elements[isbn] = std::make_pair(queue.begin(), isbn);
          }
          if(elements.size() == c_size+1)
          {
              std::cout<<queue.back()<<std::endl;
              elements.erase(queue.back());
              queue.pop_back();
          }
      }
      int lookup(int isbn)
      {
          int price = -1;
          auto it = elements.find(isbn);
          if (it != elements.end())
          {
             int price = (it->second).second;
             auto new_it = move_to_front((it->second).first);
             elements[isbn] = std::make_pair(new_it, isbn);
          }
          return price;
      }
      void remove(int isbn)
      {
         auto it = elements.find(isbn);
         if(it!=elements.end())
         {
             queue.erase((it->second).first);
             elements.erase(it);
         }
      }
};


int main()
{
  
    ISBNCache cache;
    cache.c_size = 3;
    cache.insert(1, 100);
    cache.insert(2, 200);
    cache.insert(1, 100);
    cache.insert(3, 300);
    cache.insert(4, 400);
    cache.lookup(3);
    std::cout<<cache.queue.front()<<","<<cache.queue.size()<<std::endl;
    return 0;
}
