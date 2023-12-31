#include <iostream>
#include <memory>
#include <limits>
#include <cassert>
#include <vector>

/*

Question: Dutch national flag problem: Sort elements around a pivot. Elements less than a pivot 
go to the left of the pivot and the ones greator than pivot go to the right

Key Idea:
Straightforward approach:
If you can comprimize O(n) space, then you can out the elements in another array as you traverse the array
and reorganize it in the original array. Another approach to acheive this without using space uses O(n^2)
approach.

Optimized approach:
You can do it with O(1) space as you traverse the array. In the first pass, you move all elements less than the pivot to the 
beginning of the array. In the second pass, you move elements greater than the pivot to the right of the array. 

There is another approach that does it in one pass, but need to revise this one later as the seapping logic was unclear.

*/

typedef enum {kRed, kWhite, kBlue} Color;

void DutchFlagPartition (int pivot_index, std::vector<Color>& A)
{
   Color pivot = A[pivot_index];
   int smaller = 0;
   for(int i = 0 ; i < A.size() ; i++)
    {
           if(A[i] < pivot)
           {
               std::swap(A[i], A[smaller++]);
           }
    }
    int larger = A.size() - 1;
    for(int i = A.size()-1; i >= 0 ; i--)
    {
        if(A[i] > pivot)
        {
             std::swap(A[i], A[larger--]);
        }
    }
}

int main()
{ 
   std::vector<Color> vec = {kBlue, kRed, kRed, kWhite,kRed, kRed, kBlue};
   DutchFlagPartition(3, vec);
   return 0;
}
