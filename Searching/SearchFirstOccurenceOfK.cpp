#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>

/*

Question (EPI 11.1): 
Search a sorted array for the first occurence of k.

Straightforward approach:
Binary search for the first occurence of k and search back for the
first occurence. Worst case time complexity is O(n) in case all the 
entries are equal to k.

Optimized approach:
When you find the first k, you know that elements after that cannot 
be the first occurence, so you can discard the subarray after that.
The time complexity is O(n) as the size of the candidate set
is reduced by half in each iteration. 

*/

int SearchFirstOccurenceOfK(std::vector<int> vec, int k)
{
    int result = -1; // not found
    int left = 0; int right = vec.size() - 1; 
    
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(vec[mid] > k)
        {
            right = mid-1;
        }
        else if (vec[mid] == k)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            // vec[mid] < k
            left = mid + 1;
        }
    }

    return result;
}

int main()
{ 
   std::vector<int> vec = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
   std::cout<<SearchFirstOccurenceOfK(vec, 108);
   std::cout<<SearchFirstOccurenceOfK(vec, 410);
   return 0;
}
