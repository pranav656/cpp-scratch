// LC1207 : Unique number of occurrences
// Company : Uber
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> val_occurrences_map;
        set<int> counts;

        for(auto& num : arr)
        {
            val_occurrences_map[num]++;
        }
        for(auto& el : val_occurrences_map)
        {
            if(counts.count(el.second)) return false;
            counts.insert(el.second);
        }
        return true;
    }
};
