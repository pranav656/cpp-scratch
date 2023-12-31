#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>

/*

Question (EPI 11.4): 
Write a program that takes a non-negative integer and returns the
largest integer whose square is less than or equal to the given integer. 

Straightforward approach:
Iterate from 1 to k and stop at the moment wher the square becomes greater 
than k. The time complexity is O(k).

Optimized approach:
Take the midpoint from as 0 to k and compute the square of the mipoint.
If the square of the midpoint is less than k, then we know that integers upto
the midpoint have squares less than k, so we increment the midpoint.
If square of the midpoint is greater than k, then we increment the right
end point to less than mid - 1, since integers upto the mid won't satisfy our condition.
[21] -> mid = 10, mid^2>21 --> update right = 9
mid = 4, mid^2 <21, update left = 5
mid = 7 (5+9/2), mid^2 > 21, update right = 6
mid = 5, mid^2>21, update right = 4
right endpoint is less than left endpoint, so we can return 
left endpoint -1 or the right endpoint(to be verified).
Time complexity of this approach is O(logk).

*/

int IntSquareRoot(int k)
{
    int left = 0; int right = k; 
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        unsigned long long mid_squared = mid*mid;
        if(mid_squared <= k)
        {
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left - 1;
}

int main()
{ 
   std::cout<<IntSquareRoot(300);
   return 0;
}
