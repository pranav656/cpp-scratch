// LC572 - Subtree of Another Tree
class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) return true;
        if(root1 && root2 && (root1->val == root2->val))
        {
            bool isSameLeft = isSameTree(root1->left, root2->left);
            bool isSameRight = isSameTree(root1->right, root2->right);
            return (isSameLeft && isSameRight);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
