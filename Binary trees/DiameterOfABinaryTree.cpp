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
    int diameterHelper(TreeNode* root, int& d)
    {
        if(!root) return 0;
        int lHeight = diameterHelper(root->left, d);
        int rHeight = diameterHelper(root->right, d);
        // keep track of the maximum diameter
        d = max(d, lHeight+rHeight);
        return 1 + max(lHeight, rHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        diameterHelper(root, d);
        return d;
    }
};
