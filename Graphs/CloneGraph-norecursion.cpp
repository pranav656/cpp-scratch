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

unordered_map<Node*, Node*> copied_vertices;

Node* cloneGraph(Node* node)
{
   if(!node)
   {
       return nullptr;
   }
   stack<Node*> s;
   s.push(node);
    // First loop - clone only nodes
    while(!s.empty())
    {
       Node* curr = s.top();
       s.pop();
       if(copied_vertices.find(curr) == copied_vertices.end()) 
       {
          Node* clone = new Node(curr->val, std::vector<Node*>{});
          copied_vertices[curr] = clone;
          for (Node* n : curr->neighbours)
          {
              if(copied_vertices.find(n) == copied_vertices.end() && n != nullptr)
              {
                  s.push(n);
              }
          }
        }
    }
    // Second loop - add link to neighbours
    set<Node*> visited;
    s.push(node);
    while(!s.empty())
    {
       Node *curr = s.top();
       s.pop();
       if(visited.find(curr) == visited.end())
       {
          visited.insert(curr);
          Node* cl = copied_vertices[curr];
          for (Node* n : curr->neighbours)
          {
              cl->neighbours.push_back(copied_vertices[n]);
              if(visited.find(n) == visited.end())
              {
                  s.push(n);
              }
          } 
       }
    }
    
    return copied_vertices[node];
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
