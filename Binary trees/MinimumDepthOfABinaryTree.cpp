// LC111 - Minimum Depth of a Binary Tree
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        int l = INT_MAX, r = INT_MAX;
        if(root->left) l = minDepth(root->left);
        if(root->right) r = minDepth(root->right);
        return 1 + (min(l, r));
    }

};
