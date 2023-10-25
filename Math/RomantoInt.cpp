// LC13 Roman to Integer
// We need to build the number from left to right
// if the next number is greater than the current one,
// then we need to subtract it like for the case of IV
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> mp {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for(int i = 0; i<s.size()-1; i++)
        {
            if(mp[s[i]] < mp[s[i+1]])
            {
                // for the case of numbers like
                // IV = 4 = 5-1
                res = res - mp[s[i]];
            }
            else
            {
                res = res+mp[s[i]];
            }
        }
        res+=mp[s[s.size()-1]];
        return res;
    }
};
