/*

Question: Check if a tree is symmetric

Definition of symmetric Tree:
Left subtree is same as the right sub tree, i.e the tree is equal to it's mirror

Key Idea:
In this approach I first mirror the tree and check for equality.
A more optimal approach of the solution is present in EPI book.

*/

#include <iostream>
#include <cmath>
#include <assert.h>

using namespace std;

class Node
{
public:
   Node(int d, Node*l, Node* r):data(d),left(l), right(r){}
   int data;
   Node* left;
   Node* right;
};

void PrintInOrderTraversal(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    PrintInOrderTraversal(node->left);
    std::cout<<node->data;
    PrintInOrderTraversal(node->right);
}

void MirrorNodeonTraversal(Node* node)
{   
   if (node == nullptr)
   {
       return;
   }
   Node *tmp = node->left;
   node->left = node->right;
   node->right = tmp;
   tmp=nullptr;
   MirrorNodeonTraversal(node->left);
   MirrorNodeonTraversal(node->right);
}

Node* cloneBinaryTree(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    Node* root_copy = new Node(root->data, nullptr, nullptr);
    root_copy->left = cloneBinaryTree(root->left);
    root_copy->right = cloneBinaryTree(root->right);
    return root_copy;
}

Node* getTreeMirror(Node* root)
{
    Node* root_copy = cloneBinaryTree(root);
    MirrorNodeonTraversal(root_copy);
    return root_copy;
}

bool AreBinaryTreesEqual(Node* root1, Node*root2)
{
   if(root1 == nullptr && root2 == nullptr)
   {
       return true;
   }
   if(root1!=nullptr && root2!=nullptr)
   {
      return (root1->data == root2->data) && AreBinaryTreesEqual(root1->left, root2->left)
              && AreBinaryTreesEqual(root1->left, root2->left);
   }
   
   return false;
}

int main() { 
    Node *good_weather_1 = nullptr;
    Node *good_weather_2 = new Node (1, nullptr, nullptr);
    Node *good_weather_3 = new Node(1, new Node(2, new Node(1, nullptr, nullptr), nullptr),
    new Node(2, nullptr, new Node(1, nullptr, nullptr)));
    
    Node *bad_weather_1 = new Node (1, new Node (2, nullptr, nullptr), new Node (3, nullptr, nullptr));
    Node *bad_weather_2 = new Node(1, 
    new Node(2, new Node(4, nullptr, nullptr), nullptr), 
    new Node(3, nullptr, new Node (5, nullptr, nullptr)));
    
    std::cout<<AreBinaryTreesEqual(good_weather_1, getTreeMirror(good_weather_1))<<std::endl;
    std::cout<<AreBinaryTreesEqual(good_weather_2, getTreeMirror(good_weather_2))<<std::endl;
    std::cout<<AreBinaryTreesEqual(good_weather_3, getTreeMirror(good_weather_3))<<std::endl;

    std::cout<<AreBinaryTreesEqual(bad_weather_1, getTreeMirror(bad_weather_1))<<std::endl;
    std::cout<<AreBinaryTreesEqual(bad_weather_2, getTreeMirror(bad_weather_2))<<std::endl;
    //std::cout<<AreBinaryTreesEqual(bad_weather_3, getTreeMirror(bad_weather_3))<<std::endl;
    
    return 0;
}
