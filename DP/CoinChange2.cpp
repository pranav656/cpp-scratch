// Only difference with Coin change 1
// is that you need to return the number of 
// combinations that lead to the amount. So instead of minimizing
// it, just keep accumulating the combinations for each amount.
// Same problem as combination sum. 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int c : coins)
        {
            for(int i = 1; i<amount+1; i++)
            {
               if(i - c >= 0)
                {
                        dp[i] = dp[i] + dp[i-c];
                }
            }
        }
        return dp[amount];        
    }
};
