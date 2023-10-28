// LC104 - Max depth of binary tree
// Recursive solution : Time complexity - O(n), 
// Space complexity O(h) where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int HeightLeft = maxDepth(root->left);
        int HeightRight = maxDepth(root->right);
        return 1+max(HeightLeft, HeightRight);
    }
};
