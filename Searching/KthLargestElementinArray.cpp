
#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <random>

/*

Question (EPI 11.4): 
Find k largest element in an array.

Straightforward approach:
Sort the array and take the kth last element from the end.
Time complexity is O(nlogn). But this is not needed as it does
a lot of unnecessary operations. Another approach is to use max heap.
It will yield a O(nlogk complexity) and space complexity of O(k).

Optimized approach:
The more optimal approach would be to use a quick sort approach.
Choose a random pivot and and sort the array in place. If there are 
exactly k-1 elements greater than the pivot the pivot is the kth largest element.
If there are more than k-1 elements greater than than the pivot, then we 
can ignore elements less than or equal to the pivot, and reorganize the
rest of the array around a new pivot.
If there are less than k-1 elements greater than the pivot, we can discard
the elements greater than the pivot and reorganize the array on a new pivot.

The space complexity of this approach is O(1). The average time complexity is O(n)
and worst case time complexity is O(n^2 when the randomly selected pivot is either the
largest or the smallest element in the array.)

*/

template <typename Compare>
int PartitionAroundPivot(int left, int right, int pivot_idx, Compare comp, std::vector<int>& A)
{
    int pivot_value = A[pivot_idx];
    int new_pivot_idx = left;
    std::swap(A[pivot_idx], A[right]);
    for (int i = left; i < right; i++) {
        if (comp(A[i], pivot_value)) {
            std::swap(A[i], A[new_pivot_idx++]);
        }
    }
    std::swap(A[right], A[new_pivot_idx]);
    return new_pivot_idx;
}

template <typename Compare>
int FindKth(int k, Compare comp, std::vector<int>& A)
{
    int left = 0, right = A.size() - 1;
    std::default_random_engine gen((std::random_device())());
    while (left <= right) {
        int pivot_idx = std::uniform_int_distribution<int>{ left, right }(gen);
        int new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, comp, A);
        if (new_pivot_idx == k - 1) {
            return A[new_pivot_idx];
        }
        else if (new_pivot_idx > k - 1) {
            right = new_pivot_idx - 1;
        }
        else {
            left = new_pivot_idx + 1;
        }
    }
}

int FindKthLargest(int k, std::vector<int>& A)
{
    return FindKth(k, std::greater<int>(), A);
}

int main()
{
    std::vector<int> A = { 3, 1, -1, 2 };
    std::cout << FindKthLargest(2, A);
    std::cout << FindKthLargest(4, A);
    return 0;
}
