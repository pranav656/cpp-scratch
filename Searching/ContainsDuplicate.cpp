// LC217 - Contains Duplicate
// Brute force: search for
// every possible pair of numbers
// optimized solution, use a hashset
// Time complexity O(nlog(n)). space 
// complexity O(n)
// Another approach is to sort and search
// for duplicates. no additional memory is
// needed in this case.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen_nums;
        for(auto num : nums)
        {
            if(seen_nums.count(num)) return true;
            seen_nums.insert(num);
        }
        return false;
    }
};
