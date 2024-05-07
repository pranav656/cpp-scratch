/**
 LC102 - Binary Tree Level Order Traversal
 */
class Solution {
private:
        vector<vector<int>> sol;
public:
    void levelOrderHelper(TreeNode* root, int depth)
    {
        if(root == nullptr) return;
        // If sol size is depth, increase
        // size by one to add more solutions
        if(sol.size() == depth)
        {
            sol.push_back(vector<int>());
        }
        sol[depth].push_back(root->val);
        levelOrderHelper(root->left, depth+1);
        levelOrderHelper(root->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrderHelper(root, 0);
        return sol;
    }
};

// queue based approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(root == nullptr) return sol;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            // depending on the size, pop
            int levelsize = q.size();
            vector<int> currentLevel;
            for(int i = 0; i<levelsize; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            sol.push_back(currentLevel);
        }
        return sol;
    }
};
