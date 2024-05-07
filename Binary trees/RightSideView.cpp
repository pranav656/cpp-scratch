// LC199 - Binary Tree right side view
// recursion
class Solution {
private:
    vector<int> sol;
    void Helper(TreeNode* root, int height)
    {
        if(root == nullptr) return;
        if(sol.size() == height) sol.push_back(root->val);
        Helper(root->right, height+1);
        // in case only left path is present, 
        // it needs to be processed
        Helper(root->left, height+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        Helper(root, 0);
        return sol;
    }
};

// iterative
// LC199 - Binary Tree right side view
class Solution {
private:

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        if(root == nullptr) return sol;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i<n; i++)
            {
                TreeNode* curr = q.front();
                if(i == n-1) {
                    // take the right most node
                    sol.push_back(curr->val);
                }
                q.pop();
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }
        }
        return sol;
    }
};
