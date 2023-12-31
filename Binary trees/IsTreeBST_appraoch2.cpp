#include <iostream>
#include <memory>
#include <limits>

/*
Key Idea:
This is the same approach, just that we go through the tree in order and if the conditions are not satisfied through the traversal, then we set a boolean to false.

Time Complexity o(N)
Space: O (1), if function call stack is not considered, else O(H) where H is the height of the tree

TODO: This can also be implemented without recursion. 
*/
class Node
{
public:
   Node(int d, Node*l, Node* r):data(d),left(l), right(r){}
   int data;
   Node* left;
   Node* right;
};

void TraverseTree(Node* root, int min, int max, bool& condition)
{
    if(root == nullptr) return;
    TraverseTree(root->left, min, root->data, condition);
    if(( (root->data) < min) || ((root->data) > max)) {condition = false;}
    TraverseTree(root->right, root->data, max, condition);
}

bool IsTreeBST(Node* root)
{
    bool condition = true;
    TraverseTree(root,std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), condition);
    return condition;
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
    std::cout<<IsTreeBST(&BW3);
    std::cout<<IsTreeBST(&BW4);
    return 0;
}
