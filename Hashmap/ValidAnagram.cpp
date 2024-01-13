// LC242 - Easy

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> chars;
        for(auto& c: s)
        {
            chars[c]++;
        }
        for(auto& c: t)
        {
            if(chars.find(c) != chars.end())
            {
                chars[c]--;
            }
        }
        for(auto it = chars.begin(); it != chars.end(); it++)
        {
            if(it-> second != 0) return false;
        }

        return true;
    }
};
