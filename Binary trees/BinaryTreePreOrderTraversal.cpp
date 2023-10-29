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


// LC144 - Binary Tree Preorder Traversal
// Iterative implementation
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            res.push_back(curr->val);
            // push right first and left so as to
            // reverse order of traversal
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return res;
    }
};
