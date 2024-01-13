// LC347 - Top k frequent element
// O(n) time+memory complexity solution assuming O(1) for hash table lookup
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;
        vector<vector<int>> frequency_map(nums.size()+1, vector<int>{});
        vector<int> ans;
        for(auto& num : nums)
        {
            counts[num]++;
        }
        for(auto& it : counts)
        {
            frequency_map[it.second].push_back(it.first);
        }
        for(int i = frequency_map.size()-1; i>= 0; i--)
        {
            if(k == 0) return ans;
            for(auto& el : frequency_map[i])
            {
                ans.push_back(el);
                k--;
            }
        }

        return ans;
    }
};
