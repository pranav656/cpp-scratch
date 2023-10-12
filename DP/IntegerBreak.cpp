class Solution {
public:
    vector<int> dp;
    // top down dp approach
    int integerBreak(int n) {
        // different rule when returning answer for 
        // numbers less than 3
        // 2 --> 1,1 best combination
        // 3 --> 2,1 best combination
        // return n -1
        // for numbers larger than 3, use recursion 
        if( n <= 3) return n-1;
        dp = vector<int>(n+1, 0);
        return recurse(n);
    }
    int recurse(int n)
    {
        // for numbers less than 3, it's better
        // not to split numbers at all, so just return the 
        // whole number
        if(n <= 3) return n;
        // return the memoized answer
        if(dp[n] != 0) return dp[n];
        int ans = n;
        for(int i =2; i<n; i++) {
            // find the best possible answer
            // i * f(n-i) --> key idea
            ans = max(ans, i * recurse(n-i));
        }
        dp[n] = ans;
        return ans;
    }
};
