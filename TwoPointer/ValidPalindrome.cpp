// Just traverse the pointer from both directions
// and check if they are equal. Time complexity O(m/2),
// where m is the length of the string. Space complexity O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; int r = s.size() - 1;
        while(l<=r)
        {
            // if  not alphanumeric, then ignore
            if(!isalnum(s[l])) {l++; continue;}
            if(!isalnum(s[r])) {r--; continue;}
            // convert to lower case before comparison
            if(tolower(s[l]) == tolower(s[r])) {
                l++; r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
