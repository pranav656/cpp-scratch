#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
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
        if(max_red <= 12 && max_green <= 13 && max_blue <= 14)
        {
            //cout<<id<<endl;
            ans += id;
        }
    }
    cout<<ans<<endl;
}
