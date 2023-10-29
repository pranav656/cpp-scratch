// LC144 - Binary Tree Preorder Traversal
// Recursive implementation
class Solution {
public:
    void preOrderTraversalHelper(TreeNode* n, vector<int>& res)
    {
        if(n == nullptr) return;
        res.push_back(n->val);
        preOrderTraversalHelper(n->left, res);
        preOrderTraversalHelper(n->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrderTraversalHelper(root, res);
        return res;
    }
};
