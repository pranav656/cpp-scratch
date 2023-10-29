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

// LC145 - Binary Tree Postorder Traversal
// Iterative solution with two stacks
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode *curr = st1.top(); st1.pop();
            // current node should be
            // processed last
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        while(!st2.empty()) {
            res.push_back(st2.top()->val);
            st2.pop();
        }

        return res;
    }
};
