// LC424 - Longest repeating character replacement
// The key idea is to realize that in a given subwindow
// you just need to know the word that has the maximum frequency.
// When the window length - max word frequency (i.e. number of words
// that need to be replaced) is greater than k, then shrink the 
// window length (update the word count with the new window length).
// The time complexity of this approach is O(26.n) since 
// it recomputes the word that occurs the max frequency eveytime 
// a new window is computed.
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> word_freq(26, 0);
        int ans = 0;
        int l = 0;
        int maxCharCount = 0;
        for(int r = 0; r < s.size(); r++) {
            word_freq[s[r] - 'A'] = word_freq[s[r] - 'A'] + 1;
            while(r - l + 1 - *max_element(begin(word_freq), end(word_freq)) > k)
            {
                word_freq[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
