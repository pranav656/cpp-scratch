// (TODO) https://open.kattis.com/contests/yostym/problems/cinemaseating

#include <bits/stdc++.h>

using namespace std;



int main()
{
    int R, C;
    cin>>R>>C;
    vector<vector<bool>> rc(C, vector<bool>(R, false));
    vector<vector<short>> n(C, vector<int>(R, false));
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int r,c;
        cin>>r>>c;
        rc[r-1][c-1] = true;
    }

    for(int i = 0; i<R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            // check eight neighbours
            if((i-1>=0 && i+1<R) && (j-1>=0 && j+1<C))
            {
                if(rc[i-1][j]) n[i][j]++;
                if(rc[i-1][j-1])n[i][j]++;
                if(rc[i-1][j+1]) n[i][j]++;
                if(rc[i+1][j]) n[i][j]++;
                if(rc[i+1][j-1]) n[i][j]++;
                if(rc[i+1][j+1]) n[i][j]++;
                if(rc[i][j+1])n[i][j]++;
                if(rc[i][j-1]) n[i][j]++;
            }
        }
    }
    /*for(int i = 0; i< R; i++)
    {
        for(int j = 0; j<C; j++)
        {
            cout<<boolalpha<<rc[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    return 0;
}
