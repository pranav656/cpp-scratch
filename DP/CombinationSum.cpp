
#include <bits/stdc++.h>
/*

Question (LC39):
https://leetcode.com/problems/combination-sum/description/

Return the number of unique combination of numbers (numbers given as input) that can sum
up to a given target sum.

Solution:
This problem can be solved with recursion + back tracking.

Time Complexity is O(2^t) where t is the target
Space complexity is unclear. I guess the max size of 
a single combination can be m (i.e. a combination where
you  just have 1s summing upto the number), but what about other 
combinations? what is the maximum amount of combinations? That 
depends on the input elements. It should probably be of the order of nCx where
x is the number of elements that can sum upto a given combination.

The detailed explanation of the solution is here:
https://www.youtube.com/watch?v=GBKI9VSKdGg

*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        CombinationSumHelper(candidates, target, tmp, 0);
        return result;

    }
private:
    vector<vector<int>> result;

    void CombinationSumHelper(vector<int>& nums, int target, vector<int>& tmp, int i)
    {
        if (i >= nums.size() || target < 0) return;
        if(target == 0) {
            result.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        CombinationSumHelper(nums, target-nums[i], tmp, i);
        tmp.pop_back();
        CombinationSumHelper(nums, target, tmp, i+1);
    }
};
