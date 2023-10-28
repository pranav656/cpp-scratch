// LC104 - Max depth of binary tree
// Recursive solution : Time complexity - O(n), 
// Space complexity O(h) where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int HeightLeft = maxDepth(root->left);
        int HeightRight = maxDepth(root->right);
        return 1+max(HeightLeft, HeightRight);
    }
};

// LC104 - Max depth of binary tree
// BFS solution : Time complexity - O(n), 
// Space complexity O(m) where m is the number 
// of nodes at each level.
// Idea is to check the number of levels that exist
// Push the child nodes into the queue at each level and loop
// until the queue isemtpy
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty())
        {
            depth++;
            int len = q.size();
            for(int i = 0; i<len;i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }

        return depth;
    }
};
