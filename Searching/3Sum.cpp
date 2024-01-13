// LC15 - 3Sum
// Time complexity - O(nlogn + n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            //if(nums[i] > 0) break;
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j < k)
            {
                if(nums[j] + nums[k] < target)
                {
                    j++;
                }
                else if(nums[j] + nums[k] > target)
                {
                    k--;
                }
                else{
                    triplets.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto t : triplets)
        {
            ans.push_back(t);
        }
        return ans;
    }
};
