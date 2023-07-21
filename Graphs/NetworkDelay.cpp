
#include <bits/stdc++.h>

/*

Problem Network Delay Time (LC743):
Given a network of nodes, their (directed edges), compute how long it would 
take to send a signal from a give source to all the other nodes. 


Solution:
This problem can be solved by Dijkstra's algorithm:
You use a min heap to keep track of the distances. You pop out
from the min heap (the heap which has the minimum distance to the source node
which has not been visited), update the distance to travel to the edges
and add those distances in the min heap. Mark the current node as visited and
move onto the next node which has the nearest distance. Continue this
as long as the minheap is not empty. As you do this keep track of the max distance
that has been travelled.
If the number of visited nodes is equal to the total number of nodes
then you return the distance that has been tracked, else return -1 
since all the nodes are not reachable and that is the expected out.

*/

using namespace std;

struct Node 
{
   bool operator<(const Node& that) const
   {
      return d > that.d;
   }
   Node(int _d, int _n) : d(_d), n(_n)
   {}
   int d, n;
} ;

int NetworkDelayTime(vector<vector<int>>& times, int n, int k )
{
    int t = 0;
    unordered_set<int> visited;
    unordered_map<int, vector<vector<int>>> edges;
    // add edges and their corresponding weights
    for (auto& time : times)
    {
        edges[time[0]].push_back({time[1], time[2]});
    }
    priority_queue<Node> minHeap;
    minHeap.emplace(Node(0,k));
    while (!minHeap.empty())
    {
        Node minDistanceNode = minHeap.top();
        minHeap.pop();
        // If the node is visited continue with the 
        // next minimum node in the heap
        if(visited.find(minDistanceNode.n) != visited.end())
        {
            continue;
        }
        visited.insert(minDistanceNode.n);
        t = max(t, minDistanceNode.d);

        // calculate minimum distance to node
        for (auto & edge : edges[minDistanceNode.n])
        {
            // Check if edges of the current node have
            // not been visited
            if(visited.find(edge[0]) == visited.end())
            {
                // add the distance of the node to the visited 
                // Note: can be confusing as heap as distance first 
                minHeap.emplace(Node(minDistanceNode.d + edge[1] , edge[0]));
            }
        }
    }
    if(visited.size() == n) return t;
    return -1;
}


int main()
{
   vector<vector<int>> tc1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
   vector<vector<int>> tc2 = {{1, 2, 1}};
   vector<vector<int>> tc3 = {{1, 2, 1}};
   return 0;
}
