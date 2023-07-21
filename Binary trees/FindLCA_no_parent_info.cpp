#include <iostream>
#include <memory>
#include <limits>
#include <cassert>

/*

Question: Find the least common ancestor of a binary tree in a case where there is no parent information present in the nodes?

Key Idea:

If the query nodes are both found under the tree, it means that the tree is an ancestor, but it could be that the left and the right subtree
is also the ancestor. If the left subtree has one of the nodes and if the right subtree has one of the nodes, then the root is the LCA.
If left subtree has both the nodes, then either it is the left subtree or one of the leaves of that left subtree is the LCA, similarly for the right subtree. 

This recursion would satisfy the above conditions.

First traverse throught left and right subtrees. 
If left subtree has both the nodes, then take the result of that traversal, similarly for the right subtree.
It could be that the current node is also the common ancestor, so check for equality in the current node.
If the total number of target nodes is two found in the current node (number of nodes found in left + number of nodes found + number of nodes found equal in the 
current node).
This recursion would also work in the case where you query the ancestor of the root (which is itself).
*/

class Node
{
public:
   Node(int d, Node*l, Node* r):data(d),left(l), right(r){}
   int data;
   Node* left;
   Node* right;
};

typedef struct  
{
   int num_target_nodes;
   Node* ancestor;
} TraversalResult;

TraversalResult get_least_common_ancestor_helper(Node* tree,
                                                 Node* node1,
                                                 Node* node2)
{
    if(tree == nullptr)
    {
        return {0, nullptr};
    }

    auto left_result = get_least_common_ancestor_helper(tree->left, node1, node2);
    if (left_result.num_target_nodes == 2)
    {
        return left_result;
    }
    auto right_result = get_least_common_ancestor_helper(tree->right, node1, node2);
    if(right_result.num_target_nodes == 2)
    {
        return right_result;
    }
    int num_target_nodes = left_result.num_target_nodes + right_result.num_target_nodes + (tree->data == node1->data) + (tree->data == node2->data);
    return {num_target_nodes, num_target_nodes == 2 ? tree : nullptr};
}

Node* get_least_common_ancestor(Node* tree, Node* node1, Node* node2)
{
    auto res = get_least_common_ancestor_helper(tree, node1, node2);
    return res.ancestor;
}

int main()
{ 

   Node* last_level_1 = new Node(8, nullptr, nullptr); 
   Node* last_level_2 = new Node(7, nullptr, nullptr); 
   Node* last_level_3 = new Node(6, nullptr, nullptr); 

   Node* third_level_1 = new Node (4, last_level_1, nullptr);
   Node* third_level_2 = new Node (5, last_level_2, last_level_3);
   Node* third_level_3 = new Node (9, nullptr, nullptr);

   Node* second_level_1 = new Node(2, third_level_1, third_level_2);
   Node* second_level_2 = new Node(3, third_level_3, nullptr);
    
   Node* root = new Node (1, second_level_1, second_level_2);

   Node* good_weather_1_res = get_least_common_ancestor(root, third_level_1, third_level_2);
   Node* good_weather_2_res = get_least_common_ancestor(root, third_level_3, second_level_1);
   Node* good_weather_3_res = get_least_common_ancestor(root, third_level_3, second_level_2);
   Node* good_weather_4_res = get_least_common_ancestor(root, root, root);
   assert(good_weather_1_res->data == second_level_1->data);
   assert(good_weather_2_res->data == root->data); 
   assert(good_weather_3_res->data == second_level_2->data); 
   assert(good_weather_4_res->data == root->data);  
    
   return 0;
}
