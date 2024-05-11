/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// LC297 - Serialize and Deserialize Binary Tree
// Recursive approach with Pre-order traversal 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        // cout<<out.str()<<endl;
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream& out)
    {
        if(root)
        {
            out<< root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        if(val == "#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// LC297 - Serialize and Deserialize Binary Tree
// Queue based approach (level order traversal)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string data="";
        queue<TreeNode*> q({root});
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front) {
                data += to_string(front->val)+",";
                q.push(front->left);
                q.push(front->right);
            } else 
            {
                data += "#,";
            }
        }
        cout<<data<<endl;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0) return nullptr;

        stringstream ss(data);
        string input;
        getline(ss, input, ',');
        TreeNode* root = new TreeNode(stoi(input));
        queue<TreeNode*> q({root});
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            string left, right;
            getline(ss, left, ',');
            getline(ss, right, ',');
            // fill left and right nodes, level
            // by level
            if (left == "#") {
                front->left = nullptr;
            }
            else {
                front->left = new TreeNode(stoi(left));
                q.push(front->left);
            }

            if(right == "#") {
                front->right = nullptr;
            }
            else 
            {
                front->right = new TreeNode(stoi(right));
                q.push(front->right);
            }
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
