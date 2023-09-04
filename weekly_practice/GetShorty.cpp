/*
https://open.kattis.com/contests/cgbkbq/problems/getshorty

*/

#include <bits/stdc++.h>


using namespace std;

struct Node 
{
   bool operator<(const Node& that) const
   {
      if(that.d + numeric_limits<double>::epsilon() > d) return true;

       return false;
   }
   Node(double _d, int _n) : d(_d), n(_n)
   {}
   double d, n;
} ;

int main()
{
    int n = -1, m = -1;
    while(1)
    {
        unordered_set<int> visited;
        double min_distance = DBL_MIN;
        unordered_map<int, vector<pair<int, double>> > edges;
        cin>>n>>m;
        if(n == 0 && m == 0) break;        
        for(int i = 0; i<m; i++)
        {
            int n1, n2;
            double w;
            cin>>n1>>n2>>w;
            //w = 1.0 - w;
            edges[n1].push_back(make_pair(n2, w));
            edges[n2].push_back(make_pair(n1, w));
        }
        
        priority_queue<Node> minHeap;
        minHeap.emplace(Node(1.0000, 0));
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
                    minHeap.emplace(Node( dist , edge.first));
                    if(edge.first == n - 1)
                    {
                        min_distance = max(min_distance, dist);
                    }
                }
            }
        }
        cout<<fixed<<setprecision(4)<<min_distance<<endl;
    }    
        
    return 0;
}
