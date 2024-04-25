// LC110 - Balanced Binary Tree
class Solution {
public:
    int height(TreeNode* root)
    {
        if (!root) return 0;
        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh - rh) > 1) return false;

        bool lb = isBalanced(root->left);
        bool rb = isBalanced(root->right);
        
        return (lb && rb);
    }
};
