//LC152

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmaxProduct = nums[0];
        // since the array contains negative numbers
        // we also need a variable to track min numbers
        int currminProduct = nums[0];
        int result = currmaxProduct;
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i] < 0)
            {
                swap(currmaxProduct, currminProduct);
            }
            // If a new number occurs that breaks the chain, it will be updated
            currmaxProduct = max(nums[i], nums[i] * currmaxProduct);
            currminProduct = min(nums[i], nums[i] * currminProduct);
            result = max(currmaxProduct, result);
        }

        return result;
    }
};
