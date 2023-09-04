
#include <bits/stdc++.h>
/*
https://open.kattis.com/contests/cgbkbq/problems/islandalliances

ONLY WORKS FOR THE BASIC CASE(TODO).
Open question: SHould the graph be dynamically updated to reflect approved proposals?
*/

using namespace std;
using ull = unsigned long long;

map<int, set<int>*> graph;

int main() {
   ull n, m , q;
   cin>>n>>m>>q;
    for(int i = 0; i<m; i++)
    {  
        int u, v;
        cin >> u >> v;
        if(graph[u] == nullptr)
        {
            graph[u] = new set<int>();
            graph[u]->insert(v);
        }
        else
        {
            graph[u]->insert(v);
        }
        if(graph[v] == nullptr)
        {
            graph[v] = new set<int>();
            graph[v]->insert(u);
        }
        else
        {
            graph[v]->insert(u);
        }
    }

    for(int i = 0; i<q; i++)
    {
        int c1, c2;
        cin>>c1>>c2;
        bool distrusting_pair = false;
        if(graph.find(c1) != graph.end())
        {
            if(graph[c1]->find(c2) != graph[c1]->end())
            {
                distrusting_pair = true;
            }
        }
        else if(graph.find(c2) != graph.end())
        {
            if(graph[c2]->find(c1) != graph[c2]->end())
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
            set<int>* merged_set = new set<int>();
            //merge still wrong
           if(graph.find(c1) != graph.end() && graph[c1] != graph[c2])
           {
               if(graph[c1] != nullptr)
               { 
                    set<int> original_set_c1 = *graph[c1];
                    for(int i : original_set_c1)
                    {
                        merged_set->insert(i);
                    }
                    delete graph[c1];
                    graph[c1] = nullptr;
                }
           }
            
           if(graph.find(c2) != graph.end())
           {
               if(graph[c2] != nullptr)
               {
                      set<int> original_set_c2 = *graph[c2];
                      for(int i : original_set_c2)
                      {
                        merged_set->insert(i);
                      }
                      delete graph[c2];
                      graph[c2] = nullptr;           
               }
           }
            graph[c1] = merged_set;
            graph[c2] = merged_set;
            
        }
        else
        {
            cout<<"REFUSE"<<endl;
        }
    }
    set<int> *a = graph[1];
    for(auto i : *a)
    {
        cout<<i<<endl;        
    }
   return 0;
}
