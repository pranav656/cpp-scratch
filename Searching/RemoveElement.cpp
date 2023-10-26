// LC27 - Remove element
// Trick is to keep track of the index
// of the last seen non equal element element and
// replace the positions. 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] != val)
            {
                // Fill the kth index
                // with values not equal to target.
                // In this way, the next equal element
                // is replaced
                nums[k] = nums[i];
                k++;               
            }
        }
        return k;
    }
};
