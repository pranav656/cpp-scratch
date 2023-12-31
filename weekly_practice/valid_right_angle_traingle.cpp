#include <bits/stdc++.h>

 

/*
https://open.kattis.com/contests/y53fv3/problems/pravokutni
*/

 

using ll = long long int ;
using ull = unsigned long long int;
using xy =  std::pair<ll, ll>;

 

 

bool is_valid_triangle (xy c1, xy c2, xy c3)
{
    ll X1 = c1.first, X2 = c2.first, X3 = c3.first,
       Y1 = c1.second, Y2 = c2.second, Y3 = c3.second;

 

    ll A = (X2 - X1)*(X2 - X1)
            + (Y2 - Y1)*(Y2 - Y1);

    ll B = (X3 - X2)*(X3 - X2) + (Y3 - Y2)*(Y3 - Y2);

    ll C = (X3 - X1)*(X3 - X1) + (Y3 - Y1)*(Y3 - Y1);

    if (A == (B + C) || B == (A + C)
             || C == (A + B))
    {
        return true;
    }

 

    return false;
}

 

int main()
{
    std::vector<xy> coords;
    int n;
    std::cin>>n;
    for (int i = 0; i<n; i++)
    {
       xy coord;

       std::cin>>coord.first>>coord.second;
       coords.push_back(coord);
    }
    ll i = 0, j =0, k =0, res = 0;
    while (i < n-2)
    {
        j = i+1;
        while (j < n - 1 )
        {
            k = j+1;
            while (k < n )
            {
                if(is_valid_triangle(coords[i], coords[j], coords[k]))
                {
                    res++;
                }
                k++;
            }
           j++;
        }
       i++;
    }
    std::cout<<res;
    return 0;
}
