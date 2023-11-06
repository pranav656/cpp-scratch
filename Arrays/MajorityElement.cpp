// LC169 - Majority Element
// add the number of occurrences
// to has set and return the number which
// has the max occurences
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(auto num : nums)
        {
            counts[num]++;
        }
        for(auto it : counts)
        {
            if(it.second > nums.size()/2)
            {
                return it.first;
            }
        }
        // dummy variable, according to the problem
        // statement this should never be reached
        return counts.begin()->first;
    }
};
