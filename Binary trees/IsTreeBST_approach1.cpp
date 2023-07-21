#include <iostream>
#include <memory>
#include <limits>

/*
Key Idea:
Recursively go through each tree node and check if it satsifies BST constraints (i.e. the elements are within the ranges).
1The root should satisfy the condition (-inf, inf).
First step:
1.1 The node in the left should satisfy the condition(-inf, root).
1.2 The node in the right should satisfy the condition(root, inf).
Left Recursion:
1.1.1 The node in the left should satisfy (-inf, node)
1.1.2 The node in the right should satisfy (node, root)
...
Right Recursion:
1.2.1 The node in the right should satisfy the condition (root, inf)
1.2.1.1 The node in the left should satsify the condition (node, root)
...

Time Complexity o(N)
Space: O (1), if function call stack is not considered, else O(H) where H is the height of the tree
*/
class Node
{
public:
   Node(int d, Node*l, Node* r):data(d),left(l), right(r){}
   int data;
   Node* left;
   Node* right;
};

bool IsNodeWithinRange(Node* node, int min, int max)
{
    if(node == nullptr) return true;
    if((node-> data < min) || (node-> data > max)) return false;
    return IsNodeWithinRange(node->left, min, node->data) && IsNodeWithinRange(node->right, node->data, max);
}

bool IsTreeBST(Node* root)
{
    return IsNodeWithinRange(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}


int main()
{
    Node GW1(16, new Node(8, new Node(7, nullptr, nullptr), new Node(9, nullptr, nullptr)), new Node(20, new Node(18, nullptr, nullptr), new Node(21, nullptr, nullptr)));
    Node GW2(0, nullptr, nullptr);
    Node BW1(16, new Node(25, nullptr, nullptr), new Node(37, nullptr, nullptr));
    Node BW2(16, new Node(3, nullptr, nullptr), new Node(8, nullptr, nullptr));
    Node BW3(16, new Node(8, new Node(7, nullptr, nullptr), new Node(20, nullptr, nullptr)), new Node(20, new Node(18, nullptr, nullptr), new Node(21, nullptr, nullptr)));
    Node BW4(16, new Node(8, new Node(7, nullptr, nullptr), new Node(9, nullptr, nullptr)), new Node(20, new Node(18, nullptr, nullptr), new Node(5, nullptr, nullptr)));

    std::cout<<IsTreeBST(&GW1);
    std::cout<<IsTreeBST(&GW2);
    std::cout<<IsTreeBST(&BW1);
    std::cout<<IsTreeBST(&BW2);
    return 0;
}
