/*
https://open.kattis.com/contests/cgbkbq/problems/getshorty
TODO: COMPLETE SOLUTION
*/

#include <bits/stdc++.h>


using namespace std;

struct Node 
{
   bool operator<(const Node& that) const
   {
      return d > that.d;
   }
   Node(double _d, int _n) : d(_d), n(_n)
   {}
   int d, n;
} ;

int main()
{
    int n = -1, m = -1;
    while(n != 0 && m != 0)
    {
        unordered_set<int> visited;
        double min_distance = DBL_MIN;
        unordered_map<int, vector<pair<int, double>> > edges;
        cin>>n>>m;
        for(int i = 0; i<m; i++)
        {
            int n1, n2;
            double w;
            cin>>n1>>n2>>w;
            //w = 1.0 - w;
            edges[n1].push_back(make_pair(n2, w));
        }
        priority_queue<Node> minHeap;
        minHeap.emplace(Node(1.0, 0));
        while(!minHeap.empty())
        {
            Node minDistanceNode = minHeap.top();
            minHeap.pop();
            if(visited.find(minDistanceNode.n) != visited.end())
            {
                continue;
            }
            visited.insert(minDistanceNode.n);
            // calculate minimum distance to node
            for (auto & edge : edges[minDistanceNode.n])
            {
                // Check if edges of the current node have
                // not been visited
                if(visited.find(edge.first) == visited.end())
                {
                    // add the distance of the node to the visited 
                    // Note: can be confusing as heap as distance first 
                    
                    double dist = minDistanceNode.d * edge.second;
                    
                   /* if(minDistanceNode.d == 0.0)
                    {
                        dist = edge.second;
                    }
                    else
                    {
                        dist = minDistanceNode.d * edge.second;
                    }*/
                    minHeap.emplace(Node( dist , edge.first));
                    if(edge.first == n - 1)
                    {
                        min_distance = max(min_distance, dist);
                        //cout<<n-1<<" "<<min_distance<<endl;
                    }
                }
            }

            if(visited.size() == m - 1)
            {
                cout<<n-1<<" "<<min_distance<<endl;
            }
        }
    }    
    return 0;
}
