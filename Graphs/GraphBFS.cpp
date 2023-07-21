/*

Question (Blind75): 
Clone a connected undirected graph

Solution:
This problem can either be done with breadth first or depth first
search. 

This one is DFS but a non recursive attempt


*/

#include <bits/stdc++.h>

using namespace std;


class Node
{
   public:
      int val;
      std::vector<Node*> neighbours;
      Node(int _val, std::vector<Node*> _neighbours)
      : val(_val), neighbours(_neighbours) {}
};

void bfs(Node* node)
{
   if(!node)
   {
       return;
   }
    set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if(visited.find(curr) == visited.end())
        {
           cout<<curr->val;
           visited.insert(curr);
           for (Node* n : curr->neighbours)
           {
               q.push(n);
           }   
        }
    }
    
    
}

int main() { 
    std::vector<Node*> neighbours{};
    // initialize vectors with zero neighbours
    Node* v1 = new Node(1, neighbours);
    Node* v2 = new Node(2, neighbours);
    Node* v3 = new Node(3, neighbours);
    Node* v4 = new Node(4, neighbours);
    Node* v5 = new Node(5, neighbours);

    // use assign for initializer list
    v1->neighbours.assign({v2, v4});
    v2->neighbours.assign({v1, v3});
    v3->neighbours.assign({v2, v4, v5});
    v4->neighbours.assign({v1, v3});

    bfs(v1);
    
    return 0;
}
