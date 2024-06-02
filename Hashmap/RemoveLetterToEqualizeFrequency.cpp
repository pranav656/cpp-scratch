// LC2423 - Remove letter to equalize frequence
// Company : Bloomberg
// Approach: remove character
// from frequency map and 
// check if there exists only one
// frequency in the set
class Solution {
public:
    map<char, int> char_freq;
    bool equalFrequency(string word) {
        set<int> count_freq;
        set<char> chars(word.begin(), word.end());
        for(char c : word)
        {
            char_freq[c]++;
        }

        for(auto c : chars)
        {
            // remove character and
            // check if the condition is met
            char_freq[c]--;
            set<int> freqs;
            for(auto [c, fr] : char_freq)
            {
                if(fr) freqs.insert(fr);
            }
            if(freqs.size() == 1) return true;
            char_freq[c]++;
        }
        return false; 
    }
};
