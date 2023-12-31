
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>

/*
Problem (EPI13.1): 
Compute the intersection of two sorted arrays.

Straightforward approach:
Go through the first array and search for the occurrence of the element
in the second array. This brute force approach has complexity of 
O(mn). You can also optimize this approach by using Binary search
and improve the time complexity to O (mlogn) where m and n are the sizes
of the arrays respectively. This is the best solution when one array set
is smaller than the other.

Optimized approach:
We can iterate through the array, if the elements are equal we
add them to the intersection, and advance the iterator to
both the arrays. If not, advance the iterator in the smaller one.
In that way you proceed through the elements which don't matter anymore.
You can also ignore the element if the the element is same as the previous element
since we checked for the first occurence already. The time complexity of the approach is
O(m+n).

*/

std::vector<int> FindIntersection(std::vector<int> A,
                                  std::vector<int> B)
{
    std::vector<int> intersection_A_B;
    int i = 0, j = 0;
    while (i<A.size() && j<B.size())
    {
        if((A[i] == B[j]) && ((i == 0) || (A[i-1] != A[i]))) {
            intersection_A_B.emplace_back(A[i]);
            ++i; ++j;
        } 
        else if (A[i] < B[j])
        {
            ++i;
        }
        else {
           // B[j] < A[i]
            ++j;
        }
    }

    return intersection_A_B;
}

int main()
{
    std::vector<int> A = {1,2,3,4,5};
    std::vector<int> B = {2,3,4,5,6};
    std::vector<int> intersection_A_B = FindIntersection(A, B);
    for (auto i : intersection_A_B)
    {
       std::cout<<i<<std::endl;        
    }
    return 0;
}
