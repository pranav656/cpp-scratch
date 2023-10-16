// https://open.kattis.com/problems/flowergarden

#include <bits/stdc++.h>

using namespace std;

long double getShortestDistance(int x1, int y1, int x2, int y2)
{
    // hypotenuse is the shortest distance
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

bool isPrime(int num)
{
    if( num < 2) return false;
    if( num == 2) return true;
    for(int i = 2; i <= ceil(sqrt(num)) ; i++)
    {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    cin>>T;
    for(int t = 0; t<T; t++)
    {
        int startx = 0;
        int starty = 0;
        long double d = 0.0;
        int max_flowers_waterable = 0, sol = 0;
        int N = 0;
        cin>>N;
        long double D=0.0;
        cin>>D;
        for(int i = 0; i<N; i++)
        {   
            int currx = 0;
            int curry = 0;
            cin>>currx>>curry;
            d += getShortestDistance(startx, starty, currx, curry);
            // cout<<setprecision(4)<<d<<endl;
            if(d <= D) 
            {
                max_flowers_waterable++;
                //cout<<max_flowers_waterable<<endl;
                //cout<<d<<endl;
                if(isPrime(max_flowers_waterable)) {
                    sol = max_flowers_waterable;
                }
            }
            startx = currx; starty = curry;
        }
       cout<<sol<<endl;       
    }

    
    return 0;
}
