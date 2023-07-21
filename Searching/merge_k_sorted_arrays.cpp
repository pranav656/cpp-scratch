#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cassert>
#include <vector>
#include <queue>

/*

Question (EPI 10.1): 
Given a bunch of sorted arrays, merge them together while keeping the order

Key Idea:
Straightforward approach:
Merge all the arrays sort them, the complexity is O(nlogn).

Optimized approach:
Take the presorted arrays and put them in a min heap, sort them by the value of the first element.
Pop out the vector, insert the first element into result and resort the array after moving the pointer to the next element.
In this way the minheap is filled with vectors where the vector with the smallest element is on the top. 
As you fill the result array you always fill the lowest possible element from the vectors. The extract min 
and insert take O(logk) time, for n elements, the time complexity os O(nlogk) where k is the nuber of arrays.
The space complexity is O(k) beyond the memory needed to write the final result,
 this is better than O(n) where n<<k. This is better than a merge sort
based implementation where the time complexity would be O(nlogk) and space complexity would be O(n).

*/

struct IteratorCurrentAndEnd{
   bool operator>(const IteratorCurrentAndEnd& that) const {
       return *current > *that.current;
   }
   std::vector<int>::const_iterator current;
   std::vector<int>::const_iterator end;
};

std::vector<int> merge_sorted_arrays(std::vector<std::vector<int>> sorted_arrays)
{
    std::priority_queue<IteratorCurrentAndEnd, std::vector<IteratorCurrentAndEnd>, std::greater<IteratorCurrentAndEnd>> min_heap;

    for(const std::vector<int>& sorted_array : sorted_arrays) {
        if(!sorted_array.empty())
        {
            min_heap.emplace(IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()});
        }
    }
    std::vector<int> result;
    while(!min_heap.empty())
    {
       IteratorCurrentAndEnd smallest_array = min_heap.top();
       min_heap.pop();
       result.emplace_back(*smallest_array.current); 
       if(std::next(smallest_array.current) != smallest_array.end) {
           min_heap.emplace(IteratorCurrentAndEnd{std::next(smallest_array.current), smallest_array.end});
       }
    }
    return result;
}

int main()
{ 
   std::vector<std::vector<int>> vec = {{3,5,7}, {0,6}, {0,6,28}};
   std::vector<int> precomputed_res = {0, 0, 3, 5, 6, 6, 7, 28};
    
   auto result = merge_sorted_arrays(vec);
   for (int i = 0; i<precomputed_res.size(); i++)
   {
      assert(precomputed_res[i] == result[i]);        
   }
   return 0;
}
