class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // INT_MAX -1 since sometimes the addtion
        // with one exactly will reach the limit
        // see loop
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int i = 1; i<(amount+1); i++)
        {
            for(int c : coins)
            {
                if(i - c >= 0)
                {
                    dp[i] = min(dp[i], 1+dp[i-c]);
                }
            }
        }

        if(dp[amount] != INT_MAX-1) return dp[amount];
        return -1;
    }
};
