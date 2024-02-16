// LC3 - Longest substring without repeating characters
// The O(n) solution requires using left and right 
// pointers (both starting from 0), keeping track of the characters
// that have been visited. when a character is seen 
// again, then you increment the left pointer
// to the point where the repeating character
// is no longer a part of the substring between l and r
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int l = 0;
        int n = s.size();
        unordered_set<char> seen;
        for(int r = 0; r < s.size(); r++)
        {
            // If the character is not seen before, then
            // a new string has been found.
            if(seen.count(s[r]) == 0)
            {
                int len = r - l + 1;
                cout<<len<<endl;
                max_len = max(len, max_len);
                seen.insert(s[r]);
            }
            // if the character has been seen before
            // move the left pointer until the
            // repeating characters is no longer
            // part of the substring between l and r
            else
            {
                //cout<<"found re:"<<s[r]<<endl;
                while(seen.count(s[r]))
                {
                    seen.erase(s[l]);
                    l++;
                }
                //the new string contains
                // one copy of the char, so add
                // it back in.
                seen.insert(s[r]);
            }
        }
        return max_len;
    }
};
