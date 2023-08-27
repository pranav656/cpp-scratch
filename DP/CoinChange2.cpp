// Only difference with Coin change 1
// is that you need to return the number of 
// combinations that lead to the amount. So instead of minimizing
// it, just keep accumulating the combinations for each amount.
// We are iterating through the coins because we don't want 
// duplicate solutions to be added. i.e. the same combination of coins
// to be added twice.
// Same problem as combination sum. Time complexity: O(a*c)
// Space complexity: O(a)

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
