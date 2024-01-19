// Custom priority queue that supports removal at any position 
// and can be useful for some type of problems.
// Note: This is an expensive removal costing O(n) due to heapify after removal. 
template<typename T, typename Comp>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, Comp>
{
  public:

      bool remove(const T& value) {
          auto it = std::find(this->c.begin(), this->c.end(), value);
       
          if (it == this->c.end()) {
              return false;
          }
          if (it == this->c.begin()) {
              // deque the top element
              this->pop();
          }    
          else {
              // remove element and re-heap
              this->c.erase(it);
              std::make_heap(this->c.begin(), this->c.end(), this->comp);
         }
         return true;
     }
};
