
#include <bits/stdc++.h>
/*
https://open.kattis.com/contests/cgbkbq/problems/blackfriday
*/

using namespace std;

map<int, pair<int, vector<int>> > counts;

int main() {
   int n;
   cin>>n;
   for(int i = 0; i<n; i++)
    {
        int d;
        cin>>d;
        if(counts.find(d) != counts.end())
        {
            counts[d].first = counts[d].first+1;
            counts[d].second.push_back(i+1);
        }
        else
        {
            counts[d].first = 1;
            counts[d].second.push_back(i+1);
        }
    }
    int max = -1, winner = -1;
    for(const auto& it : counts)
    {
        //cout<<it.second.second.size()<<endl;
        if ((it.second.first == 1) && (it.second.second.size() == 1))
        {
            if(it.first > max)
            {
                max = it.first;
                winner = it.second.second[0];
            }
        }
    }

   if(winner != -1 ) cout<<winner<<endl;
   else cout<<"None"<<endl;
   
   return 0;
}
