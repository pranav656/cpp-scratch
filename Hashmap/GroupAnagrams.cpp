// LC49
class Solution {
public:
    unordered_map<string, vector<string>> m;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto &str : strs)
        {
           auto key = str;
           // sorted string is the key
           sort(key.begin(), key.end());
            m[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};
