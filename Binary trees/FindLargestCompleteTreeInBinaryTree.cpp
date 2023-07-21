/*

Question: Find the size of the largest complete subtree given a binary tree as input.

Definition of Complete Tree:
A complete tree is one where all levels are filled, except possibily the last. The nodes
that are filled are as to the left as possible.

A perfect binary tree is a complete tree but a complete tree is not a perfect binary tree
since the last level is not complete.

Key Idea:

Starting at the root, if both the left and the right tree are perfect, 
then the entire tree is complete and the size of the largest complete subtree
is the size of the left subtree plus the right subtree plus one to include the node.
The tree is also perfect

If the left subtree is complete and the right one is perfect, and the height difference is
1, then the tree is complete

If the current node is null, then the current subtree is both complete and perfect.
Note: The definition of subtree varies from book to book, this one uses a standard definition:
The subtree is onw which the node has the root has a parent/ancestor.

Solution taken from GeeksForGeeks
*/

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

class Node {
public:
    Node(int d, Node* l, Node* r)
        : data(d)
        , left(l)
        , right(r)
    {
    }
    int data;
    Node* left;
    Node* right;
};

typedef struct
    {
    bool isComplete;
    bool isPerfect;
    int size;
    Node* subTree;
} TraversalResult;

int GetHeight(int size)
{
    return ceil(log2(size + 1));
}

/*


*/

TraversalResult TraverseNode(Node* node)
{
    TraversalResult res;
    if (node == nullptr) {
        res.isComplete = true;
        res.isPerfect = true;
        res.size = 0;
        res.subTree = nullptr;
        return res;
    }

    TraversalResult left_node_res = TraverseNode(node->left);
    TraversalResult right_node_res = TraverseNode(node->right);

    if (left_node_res.isPerfect && right_node_res.isComplete) {
        if (GetHeight(left_node_res.size) == GetHeight(right_node_res.size)) {
            res.isComplete = true;
            res.isPerfect = right_node_res.isPerfect;
            res.size = left_node_res.size + right_node_res.size + 1;
            res.subTree = node;
            return res;
        }
    }

    if (left_node_res.isComplete && right_node_res.isPerfect) {
        if (GetHeight(left_node_res.size) == (GetHeight(right_node_res.size) + 1)) {
            res.isComplete = true;
            res.isPerfect = false;
            res.size = left_node_res.size + right_node_res.size + 1;
            res.subTree = node;
            return res;
        }
    }

    res.isPerfect = false;
    res.isComplete = false;
    res.size = max(left_node_res.size, right_node_res.size);
    res.subTree = (left_node_res.size > right_node_res.size ? left_node_res.subTree : right_node_res.subTree);
    return res;
}

int getSizeofMaxCompleteSubTree(Node* root)
{
    auto result = TraverseNode(root);
    return result.size;
}

int main()
{
    Node* good_weather_1 = nullptr;
    Node good_weather_2(3, new Node(1, nullptr, nullptr), new Node(2, nullptr, nullptr));
    Node good_weather_3(5, new Node(3, new Node(1, nullptr, nullptr), new Node(2, nullptr, nullptr)), new Node(4, nullptr, nullptr));
    Node good_weather_4(5, new Node(3, new Node(1, nullptr, nullptr), new Node(2, nullptr, nullptr)), new Node(4, new Node(7, nullptr, nullptr), new Node(6, nullptr, nullptr)));
    Node good_weather_5(1, nullptr, nullptr);

    Node bad_weather_1(5, new Node(3, new Node(1, nullptr, nullptr), nullptr), new Node(4, nullptr, new Node(6, nullptr, nullptr)));
    Node bad_weather_2(5, new Node(3, new Node(1, nullptr, nullptr), new Node(2, nullptr, nullptr)), new Node(4, nullptr, new Node(6, nullptr, nullptr)));

    auto good_weather_1_res = getSizeofMaxCompleteSubTree(good_weather_1);
    auto good_weather_2_res = getSizeofMaxCompleteSubTree(&good_weather_2);
    auto good_weather_3_res = getSizeofMaxCompleteSubTree(&good_weather_3);
    auto good_weather_4_res = getSizeofMaxCompleteSubTree(&good_weather_4);
    auto good_weather_5_res = getSizeofMaxCompleteSubTree(&good_weather_5);
    auto bad_weather_1_res = getSizeofMaxCompleteSubTree(&bad_weather_1);
    auto bad_weather_2_res = getSizeofMaxCompleteSubTree(&bad_weather_2);

    assert(good_weather_1_res == 0);
    assert(good_weather_2_res == 3);
    assert(good_weather_3_res == 5);
    assert(good_weather_4_res == 7);
    assert(good_weather_5_res == 1);
    assert(bad_weather_1_res == 2);
    assert(bad_weather_2_res == 3);
}
