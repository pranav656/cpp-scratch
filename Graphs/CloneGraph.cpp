/*

Question (Blind75): 
Clone a connected undirected graph

Solution:
This problem can either be done with breadth first or depth first
search. In DFS, you go through the node, clone it first, add it
to a map (so that you don't clone it twice). You then
go to the neighbour, clone it, then do clone it until 
you have recursively visited all nodes. As you visit a neighbour you 
keep updating the list of neighbours.

The time complexity is O(V+E) since you need to visit
all the the vertices as much as the number of edges between them.
Space complexity is O(V) 


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

unordered_map<Node*, Node*> copied_vertices;

Node* cloneGraph(Node* node)
{
    if(node==nullptr) return nullptr;
    // If the vertex is already copied it is added to the map 
    if(copied_vertices.find(node) != copied_vertices.end())
    {
        return copied_vertices[node];
    }
    vector<Node*> clone_neighbours{};
    Node* clone = new Node(node->val, clone_neighbours);
    copied_vertices[node] = clone;
    for(Node* n : node->neighbours)
    {
       clone->neighbours.push_back(cloneGraph(n));  
    }
    return clone;
}

int main() { 
    std::vector<Node*> neighbours{};
    // initialize vectors with zero neighbours
    Node* v1 = new Node(1, neighbours);
    Node* v2 = new Node(2, neighbours);
    Node* v3 = new Node(3, neighbours);
    Node* v4 = new Node(4, neighbours);

    // use assign for initializer list
    v1->neighbours.assign({v2, v4});
    v2->neighbours.assign({v1, v3});
    v3->neighbours.assign({v2, v4});
    v4->neighbours.assign({v1, v3});

    Node *clone = cloneGraph(v1);
    
     // test output
    std::cout<<clone->val<<std::endl;
    std::cout<<clone->neighbours[0]->val<<std::endl;
    std::cout<<clone->neighbours[1]->val<<std::endl;
    std::cout<<clone->neighbours[0]->neighbours[0]->val<<std::endl;
    std::cout<<clone->neighbours[0]->neighbours[1]->val<<std::endl;
    return 0;
}
