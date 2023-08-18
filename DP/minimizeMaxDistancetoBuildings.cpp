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

pair<int,int> findMaxPossibleDistance(vector<vector<bool>> buildings)
{
    int res = INT_MAX, pos = 0;
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
        // for the case where there is only one 
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
        // cout<<dp[i][buildings[0].size()]<<endl;
    }
    for(int i = buildings.size()-2; i>=0; i--)
    {
        //cout<<i<<endl;
        int max_d = 0;
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
            max_d = max(dp[i][j], max_d);
        }
        dp[i][buildings[0].size()] = max_d;
        if( dp[i][buildings[0].size()] < res)
        {
            pos = i;
            res = dp[i][buildings[0].size()];
        }
    }
    return std::make_pair(res, pos);
}

int main() { 
   vector<vector<bool>> buildings = {{false, true, false}, 
                                    {true, false, false}, 
                                    {true, true, false}, 
                                    {false, true, false}, 
                                    {false, true, true}};
    auto result = findMaxPossibleDistance(buildings);
    cout <<"maximum walking distance is "<< result.first << " at block " << result.second << endl;
    return 0;
}
