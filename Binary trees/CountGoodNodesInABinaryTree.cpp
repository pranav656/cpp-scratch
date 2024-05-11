// LC1448 - Count Good nodes in Binary TREE
// Brute force solution would be to go through 
// all the nodes and check if the path had any elements
// greater than the node X. The key insight
// needed to solve this problem in an efficient
// way is to keep track of the max element seen 
// so far as you traverse the tree and if the
// node X is less than the max element seen so far,
// it's a good node and you update the result
class Solution {
private:
    int result = 0;
public:
    void helper(TreeNode* root, int max_seen_so_far)
    {
        if(root == nullptr) return;
        if(root->val >= max_seen_so_far) 
        {
            max_seen_so_far = root->val;
            result++;
        }
        helper(root->left, max(max_seen_so_far, root->val));
        helper(root->right, max(max_seen_so_far, root->val));
    }
    int goodNodes(TreeNode* root) {
        int max_seen_so_far = INT_MIN;
        helper(root, max_seen_so_far);
        return result;
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
