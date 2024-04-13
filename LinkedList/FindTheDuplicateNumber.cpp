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

// Approach 2 - Linked list
// One idea is to look at this array as a linked list
// The index represents the node and the value at the index 
// represents the next node. We need to know the Floyd's cycle
// detection algorithm to solve this problem. 
// First find the intersection point of fast and slow 
// pointers. Once that is known, you can find the
// start of the cycle by traversing from the start of the list
// and the intersection point to find the cycle start (which is the
// duplicate number in this case). TODO: Revise
// and think more about this algorithm. 
// Neetcode video explanation: https://www.youtube.com/watch?v=DfljaUwZsOk
// Time complexity : O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        // Find the intersection point
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // start slow2 from the start
        // of the list
        int slow2 = 0;
        while(slow2 != fast)
        {
            slow2 = nums[slow2];
            fast = nums[fast];
        }
        // the intersection point is
        // the start of the cycle, i.e. the duplicate.
        return slow2;
    }
};
