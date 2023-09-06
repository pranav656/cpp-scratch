
#include <bits/stdc++.h>
/*
https://open.kattis.com/contests/cgbkbq/problems/islandalliances

3rd attempt: Stopped working for the basic cases, retry after a few days.
*/

using namespace std;
using ull = unsigned long long;

vector<pair<set<int>, set<int>>> merged_islands_relationship;


void construct_relationship(int u, int v)
{
    bool ufound = false, vfound = false;
    for (int i = 0; i<merged_islands_relationship.size(); i++)
    {
        if(merged_islands_relationship[i].first.find(u) != merged_islands_relationship[i].first.end())
        {
            ufound = true;
            //cout<<"merging with existing "<<u<<":"<<v<<endl;
            merged_islands_relationship[i].second.insert(v);
            /*for(auto it : merged_islands_relationship[i].second)
            {
                cout<<it<<endl;
            }*/
        }
        if(merged_islands_relationship[i].first.find(v) != merged_islands_relationship[i].first.end())
        {
            vfound = true;
            //cout<<"merging with existing "<<v<<":"<<u<<endl;
            merged_islands_relationship[i].second.insert(u);
            /*for(auto it : merged_islands_relationship[i].second)
            {
                cout<<it<<endl;
            }*/
        }
    }
    if(!ufound)
    {
        set<int> island;
        island.insert(u);
        set<int> disagreeing_island;
        disagreeing_island.insert(v);
        merged_islands_relationship.push_back(make_pair(island, disagreeing_island));
    }
    if(!vfound)
    {
        //cout<<"merging "<<v<<":"<<u<<endl;
        set<int> island;
        island.insert(v);
        set<int> disagreeing_island;
        disagreeing_island.insert(u);
        merged_islands_relationship.push_back(make_pair(island, disagreeing_island));
    }
}

bool mergable(int u, int v)
{
    bool u_found = false, v_found=false;
    int u_idx = -1, v_idx = -1;
    for (int i = 0; i<merged_islands_relationship.size(); i++)
    {
        
        if(merged_islands_relationship[i].first.find(u) != merged_islands_relationship[i].first.end())
        {
            u_found=true;
            u_idx = i;
            if(merged_islands_relationship[i].second.find(v) != merged_islands_relationship[i].second.end())
            {
                cout<<"refused at u_idx:"<<u_idx<<endl;
                return false;
            }
        }
        if(merged_islands_relationship[i].first.find(v) != merged_islands_relationship[i].first.end())
        {
            v_found=true;
            v_idx = i;
            if(merged_islands_relationship[i].second.find(u) != merged_islands_relationship[i].second.end())
            {
                cout<<"refused at v_idx:"<<i<<endl;
                return false;
            }
        }
    }
    if(u_idx != v_idx)
    {
    if(u_found)
    {
        merged_islands_relationship[u_idx].first.insert(v);
        if(v_found)
        {
            for(auto it : merged_islands_relationship[v_idx].first)
            {
                merged_islands_relationship[u_idx].first.insert(it);
            }
            for(auto it : merged_islands_relationship[v_idx].second)
            {
                merged_islands_relationship[u_idx].second.insert(it);
            }
            merged_islands_relationship.erase(merged_islands_relationship.begin()+v_idx);
            // set false so that next condition is not evaluated 
            // to avoid double merge
            v_found = false;
        }
    }
    if(v_found)
    {
        merged_islands_relationship[v_idx].first.insert(u);
        if(u_found)
        {
            for(auto it : merged_islands_relationship[u_idx].first)
            {
                merged_islands_relationship[v_idx].first.insert(it);
            }
            for(auto it : merged_islands_relationship[u_idx].second)
            {
                merged_islands_relationship[v_idx].second.insert(it);
            }
            merged_islands_relationship.erase(merged_islands_relationship.begin()+u_idx);
        }
    }
        }
    if(!u_found && !v_found)
    {
        set<int> island;
        island.insert(u);
        island.insert(v);
        set<int> d_island;
        merged_islands_relationship.push_back(make_pair(island, d_island));
    }
    
    return true;
}


int main() {
   ull n, m , q;
   cin>>n>>m>>q;
    for(int i = 0; i<m; i++)
    {  
        int u, v;
        cin >> u >> v;
        construct_relationship(u, v);
    }
    for(int i = 0; i< q; i++)
    {
            int u,v;
            cin>>u>>v;
            if(mergable(u,v))
            {
                cout<<"APPROVE"<<endl;
            }
            else
            {
                cout<<"REFUSE"<<endl;
            }
        
    }
   return 0;
}
