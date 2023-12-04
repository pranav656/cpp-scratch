#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    ll ans = 0;
    string input;
    while (getline(cin, input))
    {
        int id;
        string game_dummy, colon_dummy, color;
        stringstream s(input);
        s >> game_dummy >> id >> colon_dummy;
        int cubes;
        int max_red = 0, max_blue = 0, max_green = 0;
        while (s >> cubes >> color)
        {
            if(color[0] == 'r')
            {
                max_red = max(max_red, cubes);
            }
            else if (color[0] == 'g')
            {
                max_green = max(max_green, cubes);
            }
            else
            {
                max_blue = max(max_blue, cubes);
            }
        }
        ll power_cubes = max_red*max_green*max_blue;
        //cout<<power_cubes<<endl;
        ans += power_cubes;
    }
    cout<<ans<<endl;
}
