// (TODO) https://open.kattis.com/contests/yostym/problems/cinemaseating

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int R, C;
    cin>>R>>C;
    array<short, 9> ans = {0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    vector<vector<bool>> rc(C, vector<bool>(R, false));
    vector<vector<short>> neighbours(C, vector<short>(R, 0));
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int r,c;
        cin>>r>>c;
        rc[r-1][c-1] = true;
    }
    /*for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            cout<<boolalpha<<rc[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            auto checkNeighbour = [&](int x, int y)
            {
                if(x > R - 1 || x < 0 || y < 0 || y > C -1) return false;
                if(rc[x][y]) return true;
                return false;
            };
            if(checkNeighbour(i+1, j+1)) neighbours[i][j]++;
            if(checkNeighbour(i+1, j)) neighbours[i][j]++;
            if(checkNeighbour(i+1, j-1)) neighbours[i][j]++;
            if(checkNeighbour(i, j+1)) neighbours[i][j]++;
            if(checkNeighbour(i, j-1)) neighbours[i][j]++;
            if(checkNeighbour(i-1, j+1)) neighbours[i][j]++;
            if(checkNeighbour(i-1, j)) neighbours[i][j]++;
            if(checkNeighbour(i-1, j-1)) neighbours[i][j]++;
            ans[neighbours[i][j]]++;
            //cout<<neighbours[i][j]<<endl;
        }
    }

    for(int i = 0; i<9; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
