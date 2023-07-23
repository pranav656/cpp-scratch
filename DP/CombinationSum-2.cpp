
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

using namespace std;

void combinationSumHelper(vector<int> &nums, int target, vector<int> &tmp,
                          int i, vector<vector<int>>& res) {
  // cout<<"recursion"<<endl;
  if (target == 0) {
    // If the target has been reached,
    // then add the temporary vector to
    // results
    res.push_back(tmp);
    return;
  }

  // till you iterate through all
  // candidates
  while (i < nums.size() && target - nums[i] >= 0) {
    // push the current candidate into a temporary solution
    tmp.push_back(nums[i]);
    combinationSumHelper(nums, target - nums[i], tmp, i, res);
    i++;
    // remove this so that you don't get 
    // duplicates in the solution
    tmp.pop_back();
  }
}

vector<vector<int>> combinationSum(int target, vector<int> nums) {
  // temporary vector to store results during backtracking
  vector<int> tmp;
  vector<vector<int>> res;
  combinationSumHelper(nums, target, tmp, 0, res);
  return res;
}

int main() {
  vector<int> a = {2, 3, 6, 7};
  vector<vector<int>> res = combinationSum(7, a);

  for (auto& vec : res)
  {
      for(auto&num : vec)
      {
          cout<<num<<" ";
      }
      cout<<endl;
  }
  return 0;
}
