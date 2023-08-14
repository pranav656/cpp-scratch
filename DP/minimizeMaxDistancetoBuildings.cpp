#include<bits/stdc++.h>

/*

[ { "gym": False, "school": True, "store": False, }, 
{ "gym": True, "school": False, "store": False, }, 
{ "gym": True, "school": True, "store": False, }, 
{ "gym": False, "school": True, "store": False, }, 
{ "gym": False, "school": True, "store": True, }, ], 
["gym","school","store"]

Find the block which is minimizes the maximum distance you
need to walk.

0 1 0
1 0 0
1 1 0
0 1 0
0 1 1


*/

using namespace std;

int findMaxPossibleDistance(vector<vector<bool>> buildings)
{
    int res = INT_MAX;
    // last element of this array 
    vector<int> distances = vector<int>(buildings[0].size()+1, INT_MAX);
    // Init DP table with inf distances
    vector<vector<int>> dp(buildings.size(), distances);
    for(int j = 0; j<buildings[0].size(); j++)
    {
        if(buildings[0][j])
        {
            dp[0][j] = 0;
        }
        dp[0][buildings[0].size()] = max(dp[0][buildings[0].size()], dp[0][j]);
        res = min(res, dp[0][buildings[0].size()]); 
    }
    for(int i = 1; i<buildings.size(); i++)
    {
        dp[i][buildings[0].size()] = 0;
        for(int j = 0; j<buildings[0].size(); j++)
        {
                if(buildings[i][j])
                {
                    dp[i][j] = 0;
                }
                else if(dp[i-1][j] != INT_MAX)
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
            dp[i][buildings[0].size()] = max(dp[i][buildings[0].size()], dp[i][j]);

        }
    }
    // problematic loop, debug later
    for(int i = buildings.size()-2; i>=0; i--)
    {
        for(int j = 0; j<buildings[0].size(); j++)
        {
            if(buildings[i][j])
            {
                dp[i][j] = 0;
            }
            else if(dp[i+1][j] != INT_MAX)
            {
                dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
            }
            if(dp[i][j] != INT_MAX)
            {
                dp[i][buildings[0].size()] = max(dp[i][buildings[0].size()], dp[i][j]);
            }    
            res = min(res, dp[i][buildings[0].size()]);
        }
    }
    return res;
}

int main() { 
   vector<vector<bool>> buildings = {{false, true, false}, 
                                    {true, false, false}, 
                                    {true, true, false}, 
                                    {false, true, false}, 
                                    {false, true, true}};
    cout<<findMaxPossibleDistance(buildings);
    return 0;
}
