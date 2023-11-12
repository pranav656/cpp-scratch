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
// LC101 - Symmetric tree
// check if left and right sub trees are symmetric
class Solution {
public:
    bool IsSymmetricHelper (TreeNode *l, TreeNode* r)
    {
        if(l==nullptr || r == nullptr) return l==r;
        bool le = IsSymmetricHelper(l->left, r->right);
        bool ri = IsSymmetricHelper(l->right, r->left);
        bool va = (l->val == r->val);
        return (le && ri && va);
    }
    bool isSymmetric(TreeNode* root) {
        return IsSymmetricHelper(root->left, root->right);
    }
};
