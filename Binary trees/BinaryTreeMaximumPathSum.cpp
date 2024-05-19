// LC124 - Binary Tree Maximum Path sum
// Find the max path for left and right
// subtree. Also for the path including
// the current node. 
class Solution {
    int dfs(TreeNode* root, int& max_path)
    {
        if(root == nullptr) return 0;
        // updates the max_path (result) while doing a dfs
        // if one of the paths is negative, it's not
        // taken into account
        int left = max(dfs(root->left, max_path), 0);
        int right = max(dfs(root->right, max_path), 0);
        int curr = root->val+left+right;
        max_path = max(max_path, curr);
        // tricky part: return the best 
        // continuous path
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        dfs(root, max_path);
        return max_path;
    }
};

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
