// LC5 - Longest Palindromic subsequence
// Brute force solution:
// Check every position in the string to check
// if it's a palindrome or not. Time complexity 
// O(N^2.N = N^3) for this solution. 
// Optimized approach: 
// Go through each position and check the substrings
// as though it's at the center and expand outwards.
// This improves time complexity to O(n^2).
// (TODO) DP approach:
// Make a DP table of size O (n*n).
// The table at (i,j) represents if 
// substring at position (i,j) is a palindrome.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // vector containing indices of the final answer
        array<int, 2> ans_idx = {0, 0};
        vector<vector<bool>> dp(n*n, false);
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
            dp[i][i+1] = true;
        }
    }
};
