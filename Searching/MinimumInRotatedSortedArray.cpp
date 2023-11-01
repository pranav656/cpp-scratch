// LC153 - Find minimum in rotated sorted array
// Variant of binary search except that the 
// array is sorted. If the right pointer is
// greater than the mid, then it has to be moved 
// further to the left so that the mid point is moved
// further. In the other cases, the left pointer 
// has to be moved further to the right to
// move towards the minima
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid =0;
        while(l <= r)
        {
            mid = l+(r-l)/2;
            if(nums[mid] < nums[r])
            {
                // if the middle point is
                // less than r, then reduce r
                // further to the left
                r = mid;
            }
            else
            {
                // if the middle point is greater
                // than the right pointer, then
                // increase the left further
                l = mid+1;
            }
        }
        return nums[mid];
    }
};
