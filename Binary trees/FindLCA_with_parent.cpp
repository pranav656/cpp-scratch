#include <iostream>
#include <memory>
#include <limits>
#include <cassert>

/*

Question: Find the least common ancestor of a binary tree in a case where parent information present in the nodes?

Key Idea:
Straightforward approach:
Go from the root to node 1 and store each of the parent in a hashmap.
Go form node 2 to root and check if the parent is already present in the hashmap. The first
hit is the least common ancestor. The space/time complexity is O(h), and h is the height of the tree.

Optimized apprach:
If the nodes are on the same depth then you just need to traverse till you find the parent
If not, you need to bring one of the traversal node to the same depth and then
traverse till you find the parent. This is the main trick.

The worst case time complexity is O(h) where you have to traverse the whole tree and the space complexity is O(1).

*/

class Node
{
public:
   Node(int d, Node*l, Node* r, Node* p):data(d),left(l), right(r), parent(p){}
   int data;
   Node* left;
   Node* right;
   Node* parent;
};

typedef struct  
{
   int num_target_nodes;
   Node* ancestor;
} TraversalResult;

int getDepth(Node* node)
{
    if (node == nullptr) return 0;
    int depth = 0;
    while (node->parent != nullptr)
    {
        depth++;
        node = node->parent;
    }
    return depth;
}

Node* get_least_common_ancestor_helper(Node* node1, Node* node2)
{
    if(node1 == nullptr || node2 == nullptr)
    {
        return nullptr;
    }
    int node1_height = getDepth(node1);
    int node2_height = getDepth(node2);
    Node* iter1 = node1;
    Node* iter2 = node2;
    if(node2_height > node1_height)
    {
        std::swap(iter1, iter2);
        std::swap(node1_height, node2_height);
    }
    int depth_diff = abs(node1_height - node2_height);
    while(depth_diff--)
    {
       iter1 = node1->parent;
    }
    while(iter1 != iter2 && (iter1 != nullptr || iter2 != nullptr))
    {
            iter1 = iter1->parent;
            iter2 = iter2->parent;
    }
    return iter1;
}

Node* get_least_common_ancestor(Node* node1, Node* node2)
{
    return get_least_common_ancestor_helper(node1, node2);
}

int main()
{ 

   
   Node* second_level_1 = new Node(2, nullptr, nullptr, nullptr);
   Node* second_level_2 = new Node(3, nullptr, nullptr, nullptr);
   Node* third_level_1 = new Node(4, nullptr, nullptr, second_level_1);
   Node* root = new Node(1, second_level_1, second_level_2, nullptr);
   second_level_1->parent = root;
   second_level_2->parent = root;
    
   Node* res = get_least_common_ancestor(third_level_1, second_level_1);
   assert(res->data == second_level_1->data);

    Node* res2 = get_least_common_ancestor(third_level_1, second_level_2);
    assert(res2->data == root->data);
    
   return 0;
}
