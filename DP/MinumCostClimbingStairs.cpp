// LC746 - Minimum Cost climbing stairs
// simple DP problem - the cost for each step
// is minimum of taking one step or two steps
// start with zero cost
// Time ans space complexity O(n)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , 0);
        for(int i = 2; i<n+1; i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
