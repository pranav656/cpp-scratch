#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Node
{
	public:
		Node(int d, Node *l, Node *r): data(d), left(l), right(r) {}

	int data;
	Node * left;
	Node * right;
};

typedef struct
{
	bool isBalanced;
	int height;
}

TraversalResult;

/*
Question: Given a binary tree, determine if it is height balanced or not.

Key Idea:
There are three conditions that need to be satisified in order for a binary tree to
be height balanced:
1. The height difference between left and right subtree should be atmost 1.
2.Left subtree and right subtree should be balanced

If the node is null, set height to zero, and the subtree is balanced.
If node is not null, then the height is basically the max of the height of left and right subtree + 1
As you traverse through the tree check if the left and the right subtrees are balanced and if the 
height of left and right subtrees don't differ my more than 1.

Note: The code below is not the best, refer to EPI book.

*/

TraversalResult TraverseNode(Node *node)
{
	TraversalResult res;
	if (node == nullptr)
	{
		res.height = 0;
		res.isBalanced = true;
		return res;
	}

	TraversalResult leftRes = TraverseNode(node->left);
	TraversalResult rightRes = TraverseNode(node->right);
	res.height = max(leftRes.height, rightRes.height) + 1;
	int diff_right_left_heights = abs(leftRes.height - rightRes.height);
	// change this condition if the balancing does not differentiate between left and right
	bool isHeightBalanced = diff_right_left_heights <= 1;
	res.isBalanced = isHeightBalanced && leftRes.isBalanced && rightRes.isBalanced;
	return res;
}

bool IsBinaryTreeHeightBalanced(Node *root)
{
	TraversalResult result = TraverseNode(root);
	return result.isBalanced;
}

int main()
{
	/*values don't matter, only height of the nodes*/
	Node GW1(1, new Node(2, new Node(3, nullptr, nullptr), new Node(4, nullptr, nullptr)), new Node(5, nullptr, nullptr));
	Node *GW2 = nullptr;
	Node GW3(1, new Node(2, nullptr, nullptr), new Node(3, nullptr, nullptr));
	Node GW4(1,
		new Node(5, new Node(7, new Node(8, nullptr, nullptr), nullptr), new Node(6, nullptr, nullptr)),
		new Node(2, new Node(4, nullptr, nullptr), new Node(3, nullptr, nullptr)));

	Node GW5(1,
		new Node(2, new Node(4, nullptr, nullptr), new Node(3, nullptr, nullptr)),
		new Node(5, new Node(7, new Node(8, nullptr, nullptr), nullptr), new Node(6, nullptr, nullptr)));

	Node BW1(1, nullptr, new Node(2, nullptr, new Node(3, new Node(4, nullptr, nullptr), new Node(5, nullptr, nullptr))));
	Node BW2(1, new Node(2, new Node(3, new Node(4, nullptr, nullptr), nullptr), nullptr), nullptr);

	std::cout << IsBinaryTreeHeightBalanced(&GW1) << std::endl;
	std::cout << IsBinaryTreeHeightBalanced(GW2) << std::endl;
	std::cout << IsBinaryTreeHeightBalanced(&GW3) << std::endl;
	std::cout << IsBinaryTreeHeightBalanced(&GW4) << std::endl;
	std::cout << IsBinaryTreeHeightBalanced(&GW5) << std::endl;

	std::cout << IsBinaryTreeHeightBalanced(&BW1) << std::endl;
	std::cout << IsBinaryTreeHeightBalanced(&BW2) << std::endl;
}
