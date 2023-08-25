
#include <bits/stdc++.h>
/*
https://open.kattis.com/contests/cgbkbq/problems/islandalliances

ONLY WORKS FOR THE BASIC CASE(TODO).
Open question: SHould the graph be dynamically updated to reflect approved proposals?
*/

using namespace std;
using ull = unsigned long long;

map<int, set<int>> graph;

int main() {
   ull n, m , q;
   cin>>n>>m>>q;

    for(int i = 0; i<m; i++)
    {  
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    for(int i = 0; i<q; i++)
    {
        int c1, c2;
        cin>>c1>>c2;
        bool distrusting_pair = false;
        if(graph.find(c1) != graph.end())
        {
            if(graph[c1].find(c2) != graph[c1].end())
            {
                distrusting_pair = true;
            }
        }
        else if(graph.find(c2) != graph.end())
        {
            if(graph[c2].find(c1) != graph[c2].end())
            {
                distrusting_pair = true;
            }
        }
        else
        {
            distrusting_pair = false;
        }

        if(!distrusting_pair)
        {
            cout<<"APPROVE"<<endl;
           // Probable bug: The merging of countries is 
           // not correct
            if(graph.find(c1) != graph.end())
            {
                for(int edge : graph[c1])
                {
                    graph[c2].insert(edge);
                }
            }
            
            if(graph.find(c2) != graph.end())
            {
                for(int edge : graph[c2])
                {
                    graph[c1].insert(edge);
                }
            }
            
        }
        else
        {
            cout<<"REFUSE"<<endl;
        }
    }
    
   return 0;
}
