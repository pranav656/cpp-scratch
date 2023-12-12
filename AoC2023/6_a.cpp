// same logic works for second part, just changes in
// input processing
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    string input;
    ll ans = 1;
    vector<vector<ll>> time_distances(2, vector<ll>{});
    int i = 0;
    while (getline(cin, input))
    {
        stringstream ss(input);
        string dummy;
        ll var;
        ss >> dummy;
        while(ss >>var)
        {
            //cout<<var<<endl;
            time_distances[i].push_back(var); 
        }
        i++;
    }
    for(int i = 0; i<time_distances[0].size(); i++)
    {
        int t = time_distances[0][i];
        //cout<<t<<endl;
        int speed = 0;
        int count = 0;
        while( t >= 0)
        {
            ll d = speed * t;
            if(d > time_distances[1][i])
            {
                count++;
            }
            speed++; t--;
        }
        ans = ans * count;
    }
    cout<<"ans:"<<ans<<endl;
}
