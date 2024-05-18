// LC993 - Cousins in a Binary Tree
// Use the definition of the problem to write
// recursive solution
class Solution {
private:
    TreeNode* parent(TreeNode* root, int x) {
        if (root == nullptr) return nullptr;
        if(root->val == x) return nullptr;
        if(root->left != nullptr && root->left->val == x) return root;
        if(root->right != nullptr && root->right->val == x) return root;
        TreeNode* p = parent(root->left, x);
        if(p != nullptr) return p;
        return (parent(root->right, x));
    }
    // helper function to find depth of node
    int depth (TreeNode* root ,int x) {
        // not more than 100 nodes
        if(root == nullptr) return 101;
        if(root->val == x) return 0;
        return min(depth(root->left, x), depth(root->right, x)) + 1;
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        return (depth(root,x) == depth(root, y) && 
                parent(root, x) != parent(root, y));
    }
};
