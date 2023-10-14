// LC45 - Jump Game II
// Extension of Jump I
// Store the max reachable positions in an array
// Simulate the best jumps and add ans as 
// you take a step. Time complexity O(n). Space
// complexity O(n) to store the max reachable 
// positions per index 
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1 ) return 0;
        int max_reachable = 0, ans = 0;
        for(int i = 0; i<nums.size();i++)
        {
            max_reachable = max(max_reachable, i+nums[i]);
            nums[i] = max_reachable;
        }
        int best_step = 0;
        while(best_step < nums.size() - 1)
        {
            ans++;
            best_step = nums[best_step];
        }
        return ans;       
    }
};
