// LC5 - Longest Palindromic subsequence
// Brute force solution:
// Check every position in the string to check
// if it's a palindrome or not. Time complexity 
// O(N^2.N = N^3) for this solution. 
// Optimized approach: 
// Go through each position and check the substrings
// as though it's at the center and expand outwards.
// This improves time complexity to O(n^2).
// DP approach:
// Make a DP table of size O (n*n).
// The table at (i,j) represents if 
// substring at position (i,j) is a palindrome.
// for "racecar" :
//1000001
//0100010
//0010100
//0001000
//0000100
//0000010
//0000001
// Note that only the right part
// of the table is filled in. i.e where i >= j
// The other case does not make sense to evalute
// i.e. string going backward is the same as
// going forward
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // vector containing indices of the final answer
        array<int, 2> ans_idx = {0, 0};
        vector<vector<bool>> dp(n, vector<bool>(n, false) );
        // This step represents filling of substrings
        // of length 1
        for(int i = 0; i<n; i++)
        {
            dp[i][i] = true;
        }
        // This represents substrings of length 2
        // starting at position i
        for(int i = 0; i< n-1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                ans_idx[0] = i;
                ans_idx[1] = i+1;
            }
        }

        // The loop below is the key idea.
        // Since we have the dp table filled for
        // strings of sizes 1 and 2, this can be used
        // for other dp table sizes
        for(int diff = 2; diff < n; diff++)
        {
            for(int i = 0; i < n - diff; i++)
            {
                int j = i + diff;
                // if the previous substring centered
                // around i,j is a palindrome and if 
                // the current positions also satisfy 
                // the condition for palindrome,  
                if(dp[i+1][j-1] && (s[i] == s[j]) )
                {
                    dp[i][j] = true;
                    ans_idx[0] = i;
                    ans_idx[1] = j;
                }
            }
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        return s.substr(ans_idx[0], ans_idx[1] - ans_idx[0] + 1);
    }
};
