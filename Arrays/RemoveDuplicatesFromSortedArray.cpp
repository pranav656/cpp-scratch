// LC26 - Remove duplicates from sorted array
// Keep track of the pointer where there are discontinuties
// and upate only those positions. Time complexity O(n)
// and space complexity O(1).
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pointer = 0;
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i] != nums[i-1])
            {
                // when not equal update
                // the not equal positions 
                pointer++; 
                nums[pointer] = nums[i];
            }
        }
        return pointer+1;
    }
};
