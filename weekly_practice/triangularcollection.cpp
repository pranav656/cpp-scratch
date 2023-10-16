#include <bits/stdc++.h>


/*
(TODO) https://open.kattis.com/contests/yostym/problems/triangularcollection
*/

using namespace std; 

using ull = unsigned long long int;
using ll = long long;

bool is_valid_triangle (ull s1, ull s2, ull s3)
{

    if (
        ((s1+s2) > s3) &&
        ((s2+s3) > s1) &&
        ((s1+s3) > s2)
        )
    {
        return true;
    }

    return false;
}

 

int main()
{
    vector<ull> sides;
    int n;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        ull s;
        cin>>s;
        sides.push_back(s);
    }
    sort(sides.begin(), sides.end());
    ll i = 0, j =0, k =0, res = 0;
    while (i < n-2)
    {
        j = i+1;
        while (j < n - 1 )
        {
            k = j+1;
            while (k < n )
            {
                if(is_valid_triangle(sides[i], sides[j], sides[k]))
                {
                    res++;
                }
                k++;
            }
           j++;
        }
       i++;
    }
    cout<<res<<endl;
    return 0;
}
