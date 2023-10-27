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
 // LC226 - Invert Binary Tree - Recursive approach
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        invertTree(root->left);
        invertTree(root->right);

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};

 // LC226 - Invert Binary Tree - BFS approach with queue
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop_front();
            // ignore if null
            if(!curr) {
                continue;
            }
            swap(curr->left, curr->right);
            if(curr->left) {
                q.push_back(curr->left);
            }
            if(curr->right) {
                q.push_back(curr->right);
            }
        }
        return root;
    }
};
