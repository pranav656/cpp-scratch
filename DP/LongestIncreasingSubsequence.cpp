// LC300

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longest_seq_at_idx(nums.size(), 1);
        for(int i = nums.size() - 1 ; i>=0; i--)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
                if(nums[i]< nums[j])
                {
                    longest_seq_at_idx[i] = max(longest_seq_at_idx[i], 1+longest_seq_at_idx[j]);
                }
            }
        }
        return *max_element(longest_seq_at_idx.begin(), longest_seq_at_idx.end());
    }
};
