// LC567 - Permutation in string
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> chars_in_s1;
        for(char c : s1)
        {
            chars_in_s1[c]++;
        }
        for(int i = 0; i<s2.size(); i++)
        {
            int matches = 0;
            if(chars_in_s1[s2[i]])
            {
                // copy the data structure so that original char frequency is not lost
                unordered_map<char, int> chars_in_s1_cp = chars_in_s1;
                int f_i = i;
                while(f_i < s2.size())
                {
                    if(chars_in_s1_cp[s2[f_i]] > 0)
                    {
                        chars_in_s1_cp[s2[f_i]]--;
                        matches++;
                        f_i++;
                        if(matches == s1.size()) return true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return false;
    }
};
