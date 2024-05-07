// LC33 - Search in a rotated Sorted array
// The idea behind this problem is to
// try to exploit the sorted nature of the list
// by doing binary search in a more optimized way.
// Find the middle and check if the left
// or the right half of the array is sorted.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return mid;
            // check if left half of the array is sorted
            if(nums[l] <= nums[mid])
            {
                // solution lies within the given range
                if((target >= nums[l]) && (target<nums[mid]))
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            // right half is sorted then
            else
            {
                if(target > nums[mid] && target <= nums[r])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
