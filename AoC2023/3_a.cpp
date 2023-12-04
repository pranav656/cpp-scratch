#include<bits/stdc++.h>

using namespace std;
using ll = long long;


bool isSymbol(const vector<string>& chars, int i, int j)
{
    if(i < 0 || i >= chars.size() || 
       j < 0 || j >= chars[0].size() )
    {
        return false;
    }
    return (chars[i][j] != '.' && !isdigit(chars[i][j]));
}

bool doesNeighbourContainSymbols(const vector<string>& chars, int i, int j)
{
    for(int i1 = -1; i1 <=1; i1++)
    {
        for(int j1 = -1; j1 <= 1; j1++)
        {
            if(i1 == 0 && j1 == 0) continue;
            if(isSymbol(chars, i+i1, j+j1)) return true;
        }
    }
    return false;
}

int main()
{
    ll ans = 0;
    vector<string> chars;
    string input;
    while (getline(cin, input))
    {
        chars.push_back(input);
    }
    int r = chars.size(), c = chars[0].size();
    for(int i = 0; i<r; i++)
    {
        int start_pos = -1;
        bool valid_num = false;
        // <= for substring 
        for(int j = 0; j<=c; j++)
        {
            char c = chars[i][j];
            if(isdigit(c))
            {
                if(start_pos == -1)
                {
                    start_pos = j;
                }
                // if neighbours contain symbols, then the number is 
                // valid
                if(doesNeighbourContainSymbols(chars, i, j))
                {
                    valid_num = true;
                }
            }
            else
            {
                // if valid number chain is broken
                if(valid_num && start_pos != -1)
                {
                    ans+=stoi(chars[i].substr(start_pos, j-start_pos));
                }
                // reset vals
                start_pos = -1;
                valid_num = false;
            }
        }
    }
    cout<<ans<<endl;
}
