// LC2958 - Length of longest subarray 
// with atmost k elements
// Brute Force : O(n^2), check all possible arrays
// Sliding Window : O(n), use a hashmap, when invalid window
// is reached, reduce window size
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> counts;
        int l = 0;
        for(int r = 0; r<nums.size(); r++)
        {
            counts[nums[r]]++;
            while(counts[nums[r]] > k)
            {
                counts[nums[l]]--;
                l++;
            }
            res = max(r-l+1, res);
        }
        return res;
    }
};
