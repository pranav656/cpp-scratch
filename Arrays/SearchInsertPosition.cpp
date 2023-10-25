// LC35 - Search insert position
// implement with binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0; int r = nums.size(); int mid = 0;
        if(target > nums[r - 1]) return r;
        while(l <= r)
        {
            mid = (l+r)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(target < nums[mid]){
                r = mid -1;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};
