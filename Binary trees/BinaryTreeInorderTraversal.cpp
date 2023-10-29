// LC94 - Binary Tree Inorder Traversal
// Standard recursive implementation 
// Time complexity - O(n), space complexity O(H) where
// H stands for the height of the tree
class Solution {
public:
    void inorderTraversalHelper(TreeNode* node, vector<int>& res)
    {
        if(node == nullptr) return;
        inorderTraversalHelper(node->left, res);
        res.push_back(node->val);
        inorderTraversalHelper(node->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalHelper(root, res);
        return res;
    }
};
