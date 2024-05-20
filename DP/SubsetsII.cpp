// LC90 - Subsets II 
// Same solution as Subsets, but sort
// and check for duplicates
// Time complexity : O(n.2^n)
// Space complexity : O(2^n)
// since you have to hold so many elements in the memory
class Solution {
private:
    void dfs(vector<int>& nums, int start, vector<int>& curr, 
        vector<vector<int>>& sol)
    {
        sol.push_back(curr);
        for(int i = start; i<nums.size(); i++)
        {
            // skip duplicates
            if(i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            dfs(nums, i+1, curr, sol);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> curr;
        // sort 
        sort(nums.begin(), nums.end());
        dfs(nums, 0, curr, sol);
        return sol;
    }
};
