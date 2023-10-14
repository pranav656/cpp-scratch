class Solution {
    vector<int> dp;
public:

    int numSquares(int n) {
        dp = vector<int>(n+1, n);
        dp[0] =0;
        for(int i = 1; i*i <= n ; i++)
        {
            int square = i*i;
            for(int j = 1; j<=n; j++)
            {
                if(j - square < 0) continue;
                dp[j] = min(dp[j], 1+dp[j-square]);
            }
        }

        return dp[n];
    }
};
