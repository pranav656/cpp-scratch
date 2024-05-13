// LC2215 - Find the difference of two arrays
// Keep track of unique elements in two sets using hash set
// in first iteration
// In second iteration place unique elements into the result
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1_nums, nums2_nums;
        set<int> sol1, sol2;
        for(auto& num : nums1)
        {
            nums1_nums.insert(num);
        }
        for(auto& num : nums2)
        {
            nums2_nums.insert(num);
        }

        for(auto& num : nums1)
        {
            if(nums2_nums.count(num) == 0)
            {
                sol1.insert(num);
            }
        }
        for(auto& num : nums2)
        {
            if(nums1_nums.count(num) == 0)
            {
                sol2.insert(num);
            }
        }
        return {vector<int>(sol1.begin(), sol1.end()),
                vector<int>(sol2.begin(), sol2.end()) };
    }   
};
