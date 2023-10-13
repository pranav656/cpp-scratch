// LC213 - House Robber II
// Extension of House Robber I
// You need to tweak the solution to HRI
// You can take two sub arrays, one that excludes
// the first element and one that excludes 
// last element (since these are connected by a
// circle). The result is the max of these two 
// subarrays
class Solution {
public:
    int helper(auto nums, int start, int end)
    {
        int n = nums.size();
        int rob1 = 0, rob2 = 0;
        for (int i = start; i<end; i++)
        {
            int tmp = max(nums[i]+rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // edge case for one element
        if(n == 1) return nums[0];
        int with_start = helper(nums, 0, n-1);
        int without_start = helper(nums, 1, n);
        return max(with_start, without_start);
    }
};
