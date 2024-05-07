// LC230 - Kth smallest element in a BST
// Approach1: Traverse the tree in order, 
// keep the elements in an array, and once
// the array sizes reach k, return the last element 
// in the array.
class Solution {
private:
    vector<int> arr;
    void Helper(TreeNode* root, int k)
    {
        if(root == nullptr) return;
        if(arr.size() == k) return;
        Helper(root->left, k);
        arr.push_back(root->val);
        Helper(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        Helper(root, k);
        return arr[k-1];
    }
};

// Improved Approach: Do not use 
// extra array space
class Solution {
private:
    vector<int> arr;
    void Helper(TreeNode* root, int& k, int& ans)
    {
        if(root == nullptr) return;
        Helper(root->left, k, ans);
        k--;
        if(k == 0) {
            ans = root->val;
            return;
        }
        Helper(root->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        Helper(root, k, ans);
        return ans;
    }
};
