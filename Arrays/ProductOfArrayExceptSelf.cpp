// LC238 - Product of array except self
// key idea is to realize that prefix and
// postfix needs to be computed without including
// the element. this can be done inplace
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        // compute the prefix first
        for(int i = 0; i<nums.size(); i++)
        {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        // 
        int postfix = 1;
        for(int i = nums.size()-1; i>=0; i--)
        {
            // this gives the product of all numbers
            // except self, that is perfix * postfix except
            // the element
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};
