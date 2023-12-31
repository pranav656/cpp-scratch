
#include <bits/stdc++.h>

/*
Problem:
Find the number of connected compoents 
in an undirected graph.

Solution:
Straightforward approach:
Do a DFS and mark the visited nodes as you do a DFS.
On subsequent DFS, if you come across the same node,
then it means you are in a connected component.
The time complexity is O(E+V+V) --> O(E+V), since
you visit the same node twice.

Union Find:
This algorithm is made for a problem like this.
Time complexity (O(V+E)??)

*/

using namespace std;

int find_parent(int n1, vector<int>& parents)
{
    int res = n1;
    // recursively find the parent node
    while (res != parents[res])
    {
        // This reduces the search space
        // shortening the parent search (path compression)
        parents[res] = find_parent(parents[res], parents);
        res = parents[res];
    }
    return res;
}

bool union_find(int n1, int n2, vector<int>& parents, vector<int>& rank)
{   
    int p1 = find_parent(n1, parents);
    int p2 = find_parent(n2, parents);

    if(p1 == p2)
    {
        return false;
    }
    if(rank[p2] > rank[p1])
    {
        // merge parent and update rank
        parents[p1] = parents[p2];
        rank[p2] += rank[p1];
    }
    else
    {
        parents[p2] = parents[p1];
        rank[p1] += rank[p2];
    }
    return true;
}

int CountConnectedComponents(int n, vector<vector<int>> edges)
{
    int res = n;
    vector<int> parents(n);
    for(int i = 0; i<n; i++)
    {
       parents[i] = i;   
    }
    vector<int> rank(n, 1);

    for (auto& edge : edges)
    {
        // every time there is a succesful union find we
        // reduce the intersection
        if(union_find(edge[0], edge[1], parents, rank))
        {
            res--;
        }
    }
    return res;
}


int main()
{
   vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
   cout<<CountConnectedComponents(5, edges);
   return 0;
}
