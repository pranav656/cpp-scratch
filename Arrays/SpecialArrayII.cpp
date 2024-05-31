// LC3152 - Special Array II
// Company : Google
// O(n^2) solution: Do all the
// queries manually and check if adjacent
// elements have same parity and add to 
// result vector.
// O(n) solution: This requires
// keeping track of adjacent elements
// that contain the same parity using
// a counter. Push the
// elements into a separate vector.
// As you parse the query, check the
// vector in which you stored the counts.
// If the counts of start/end are same, then 
// it means the subarray is special

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> cached_parity_count(1, 0);
        int count_same_parity = 0;
        for(int i = 1; i<nums.size(); i++)
        {
            if( (nums[i] %2) == (nums[i-1] % 2) ) count_same_parity++;
            cached_parity_count.push_back(count_same_parity);
        }

        for(auto & q : queries) 
        {
            ans.push_back(cached_parity_count[q[0]] == cached_parity_count[q[1]]);
        }
        return ans;
    }
};
