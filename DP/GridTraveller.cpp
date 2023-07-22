
#include <bits/stdc++.h>
/*

Question (LC62): 
You are given a 2D grid. In how many ways can you travel from
top left to the bottom right? You can only move down or right

Solution:
This is a dynamic programming problem. 

The base case is that row and column 0 have just one way of reaching
(by moving horizontally or moving down). The other cases are extentions
of this case, i.e DP[x][y] = DP[x-1][y-1] where x and y indicate
incremental moves in horizontal or vertical directions.

*/

using namespace std;
int CountWaysToEnd(int m, int n)
{
    int dp[m][n] ={{0}};
    for (int i = 0; i<m; i++)
    {
        for(int j = 0;j<n; j++)
        {
            if((i == 0) || (j == 0)) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main() { 
   cout<<CountWaysToEnd(2, 3);
    return 0;
}
