// LC647 - Palindromic Substrings
// brute force solution
class Solution {
public:
    bool isPalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if (isPalindrome(s, i, j)) ans++;
            }
        }
        return ans;
    }
};

// Optimized solution:
// The key idea behind this solution 
// is that instead of checking all possible
// substring, you can start at a position
// and expand outwards. You should take into
// account both odd and even substrings.
// Time Complexity : O(n^2), for every
// position, you have to do n checks
// of substrings.
class Solution {
public:
    // helper function to count number of palindromes 
    // starting at l, r
    int palindromeCount(string &s, int l, int r)
    {
        int count = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            int odd = palindromeCount(s, i, i);
            int even = palindromeCount(s, i, i+1);
            ans += even + odd;
        }
        return ans;
    }
};


// LC647 - Palindromic Substrings
// DP approach 
class Solution {
public:

    int countSubstrings(string s) {
        int n = s.length();
        // dp[i][j] indicates if 
        // a substring from i to j is 
        // a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        for(int len = 1; len <= n; len++)
        {
            for(int i = 0; i<n-len+1; ++i)
            {
                int j = i + len-1;
                // if length <= 2, only the first condition needs
                // to hold, for other string lengths, both
                // need to hold true
                if((s[i] == s[j]) && (len <= 2 || dp[i+1][j-1]) )
                {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
