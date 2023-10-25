// LC14 - Longest Common Prefix
// Check the smallest string. just push the common
// characters in the string till they match into the 
// result string. Time complexity (O(m*n)) where 
// m is the max length of the string and n is the size
// of the vector
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];
        string res;
        for(int i = 0; i<pref.size(); i++)
        {
            for(int j = 0; j<strs.size(); j++)
            {
                // iterate till the minum string lenths
                if(i < strs[j].size())
                {
                    if(pref[i] != strs[j].at(i))
                    {
                        return res;   
                    }
                }
                else
                {
                    return res;
                }
            }
            res.push_back(pref[i]);
        }
        return res;
    }
};
