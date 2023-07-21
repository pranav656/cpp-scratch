/*

Question: Sum the Root-To-Leaf paths in a binary tree. The tree contains only 0s and 1s. The root is represented by MSB and the leaf is the LSB.

Key Idea:
Basic Approach:
You could traverse every root to leaf path and store the numbers in a hashmap. Each path represents an integer, compute all the integers and sum the result.
The time complexity is O(Lh) where L is the number of leaves (same as the root-leaf paths) and h is the height of the map. The space complexity is O(n), given
by the size of the hashmap which is O(n).
Optimized approach:
The paths share nodes and there is no need to repeat computations. We need to construct the integers as we traverse the tree

The time and space complexity are O(n) and O(h). You would need to traverse every node atleast once (influencing the time complexity) and the space complexity is
influenced by the depth of the tree storing according to the depth.

Need more solid reasoning

*/

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Node
{
public:
   Node(int d, Node*l, Node* r):data(d),left(l), right(r){}
   int data;
   Node* left;
   Node* right;
};

int SumRootToLeafHelper(Node* tree, int partial_path_sum)
{
    if(tree == nullptr)
    {
        return 0;
    }
    partial_path_sum = partial_path_sum*2 + tree->data;
    //Logic to check if node is leaf
    if(tree->left == nullptr && tree->right == nullptr)
    {
        return partial_path_sum;
    }
    return SumRootToLeafHelper(tree->left, partial_path_sum)
           + SumRootToLeafHelper(tree->right, partial_path_sum);
}

int SumRootToLeaf(Node* tree)
{
    return SumRootToLeafHelper(tree, 0);
}

int main() { 
    Node* onelevel_tree = new Node (1, new Node(0, nullptr, nullptr), new Node(1, nullptr, nullptr));

    Node* last_level_1 = new Node(0, nullptr, nullptr);
    Node* last_level_2 = new Node(1, nullptr, nullptr);
    Node* third_level_1 = new Node(1, last_level_1, last_level_2);
    Node* third_level_2 = new Node(1, nullptr, nullptr);
    Node* second_level_1 = new Node(0, third_level_1, third_level_2);
    Node* second_level_2 = new Node(1, nullptr, nullptr);
    Node* multi_level_tree = new Node(1, second_level_1, second_level_2);
    
    assert(SumRootToLeaf(onelevel_tree)==5);
    assert(SumRootToLeaf(multi_level_tree)==29);
    return 0;
}
