// LC98 - Validate Binary Search Tree
// A simple approach to check if left is less
// and right is greater than root will not work
// because it's possible that subtrees have elements
// that are greater than the root on the left and vice
// versa on the right. 
// The key insight needed to solve this problem is to 
// keep track of maximum and minimum allowed values
// as you traverse the binary tree. 
class Solution {
public:
    bool ValidHelper(TreeNode* root, long left, long right)
    {
        if(!root) return true;
        if(root->val > left && root->val < right)
        {
            return (ValidHelper(root->left, left, root->val) &&
                    ValidHelper(root->right, root->val, right));
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return ValidHelper(root, LONG_MIN, LONG_MAX);
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
