// LC76 - Minimum window substring
// The key idea behind getting an O(n) solution 
// is to keep track of number of matches within
// a window. Start with a window with both pointers
// starting at left. Keep increasing the right pointer
// until a valid window is found (keep track of number 
// of characters that are matching). Once a matching window
// is found, shrink the window from the left and keep
// checking if the window is still valid (by keeping track 
// of the number of the matching characters). Once
// the window becomes invalid, keep searching for 
// valid solutions. As you find valid windows, keep track
// of the minimum windows you find.
// NOTE: The implementation below can be a bit more straightforward,
// but more verbose. Attempt this at a later point.
class Solution {
public:
    string minWindow(string s, string t) {
        int minLength = INT_MAX;
        int minStartPos = 0;
        // variable keeping track of number of 
        // matches to meet to take substring 
        // into consideration, if count reaches
        // zero, it means the string has
        // matched.
        int count = t.size();
        unordered_map<char, int> m;
        for (auto& c : t)
        {
            m[c]++;
        }
        int l=0, r = 0;
        while(r < s.size())
        {
            // If the current character 
            // is present in the window, then
            // there's a match, reduce count
            if(m[s[r]] > 0)
            {
                count--;
            }
            // reduce count to 
            // since r is visited, if the character
            // does not exist in the string of 
            // interest, the value in the map goes less
            // than zero, but does not affect the final solution
            m[s[r]]--;
            //increase window size 
            r++;
            while(count == 0)
            {
                // Before processing the next 
                // window, check if the existing window
                // contains the solution
                if(r - l < minLength)
                {
                    minStartPos = l;
                    // not using +1 since this does not include
                    // jth element yet
                    minLength = r-l;
                }
                // Tricky part: 
                // restore back to initial map value
                m[s[l]]++;
                // if the current window already 
                // contained the character it means
                // reducing the window length would again cause 
                // a mismatch, so increase counter length
                if( m[s[l]] > 0)
                {
                    count++;
                }
                // reduce window length from left
                l++;
            }
        }
        if(minLength != INT_MAX) return s.substr(minStartPos, minLength);
        return "";
    }
};
