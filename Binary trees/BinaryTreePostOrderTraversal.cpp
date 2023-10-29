// LC145 - Binary Tree Postorder traversal
class Solution {
public:
    vector<int> res;
    void postOrderTraversalHelper(TreeNode* root)
    {
        if(root == nullptr) return;
        postOrderTraversalHelper(root->left);
        postOrderTraversalHelper(root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrderTraversalHelper(root);
        return res;
    }
};
