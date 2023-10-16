// (TODO) https://open.kattis.com/contests/yostym/problems/guessinggame

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int lower_bound = 0;
    int upper_bound = 11;
    while (cin>>n)
    {
        if(n == 0) break;
        string s1, s2;
        cin >> s1 >> s2;
        if(s2 == "low")
        {
            lower_bound = max(n, lower_bound);
        }
        else if(s2 == "high")
        {
            upper_bound = min(n, upper_bound);
        }
        else
        {
            if((n > lower_bound) && (n < upper_bound))
            {
                cout<<"Stan may be honest"<<endl;
            }
            else
            {
                cout<<"Stan is dishonest"<<endl;
            }
            lower_bound = 0;
            upper_bound = 11;
        }
    }
    return 0;
}
