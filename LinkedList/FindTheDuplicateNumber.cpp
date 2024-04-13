// LC287 - Find the duplicate number
// Approach 1 - Binary search for the duplicate.
// We know that the integers will be in the range
// [1,n]. So, we can do a binary search based
// on the count of elements lesser than or
// equal to left and right pivots. First find
// the mid point, go through the array, and count
// the number of elements greater than or 
// equal to the midpoint. If the count of 
// the number of elements greater than the mid point
// is greater than the midpoint itself, we know that
// the real soltion lies between l and midpoint. Else,
// we know the real solution lies on the right.
// Time complexity - O(nlogn)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l+ (r-l)/2;
            int count = 0;
            for (auto& num : nums)
            {
                if(num <= mid) count++;
            }
            // If the number of elements greater 
            // than mid , then the duplicate element lies
            // left of mid
            if(count > mid) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l; 
    }
};
