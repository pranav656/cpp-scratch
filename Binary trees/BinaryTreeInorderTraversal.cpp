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

// Iterative implementation with stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> st;
        TreeNode* currNode = root;

        while(currNode != nullptr || !st.empty())
        {
            // push the left nodes first
            while(currNode != nullptr) {
                st.push(currNode);
                currNode = currNode->left;
            }
            TreeNode* poppedNode = st.top();
            st.pop();
            //push center node
            res.push_back(poppedNode->val);
            currNode = poppedNode->right;
        }
        return res;
    }
};
