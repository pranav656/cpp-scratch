// LC17 - Letter combinations of a phone number
// Backtracking solution
// Worst cast time complexity - O(n.4^n), 4
// because some digits can have 4 character combinations
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        unordered_map<char, string> m =
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string curr = "";
        vector<string> result;
        helper(digits, 0, m, curr, result);
        return result;
    }

    void helper(string digits, int idx, unordered_map<char, string>& m,
    string& curr, vector<string>& result)
    {
        if (idx == digits.size())
        {
            result.push_back(curr);
        }
        string dstr = m[digits[idx]];
        for(int i = 0; i < dstr.size(); i++)
        {
            curr.push_back(dstr[i]);
            helper(digits, idx+1, m, curr, result);
            curr.pop_back();
        }
    }
};
