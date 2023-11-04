// (TODO) LC212 - Word Search II (Hard)
// Brute force solution:
// Go through every index in the array and
// search if it matches one of the words in the
// list. Time complexity is O(w.mn4^mn).
// Optimized solution:
// The trie based solution would can reduce
// the time complexity to O(mn.4^nm).
class TrieNode
{
    public:
        static constexpr int ALPHABET_SIZE = 26;
        TrieNode* children[ALPHABET_SIZE];
        bool isEndOfWord = false;     
        TrieNode()
        {
            fill(children, children+ALPHABET_SIZE, nullptr);
        }
};

class Trie
{
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string word)
        {
            TrieNode *curr = root;
            for(char c : word)
            {
                
                if(!curr->children[c- 'a'])
                {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->isEndOfWord = true;
        }
};

class Solution {
public:
    int rows, cols;
    vector<vector<int>> visited;
    set<string> set_ans;
    Trie *t;

    void dfs(int i, int j, vector<vector<char>>& board,    
            string& path, TrieNode* root)
    {
        if(i == rows || i <0 || j < 0 || j == cols) return;
        char c = board[i][j];
        if(c == '*') return;
        TrieNode* curr = root->children[c - 'a'];
        if(curr == nullptr) return;
        path = path+c;
        cout<<c<<endl;
        // modify board to mark as visited
        board[i][j] = '*';
        if (root->isEndOfWord)
        {
            set_ans.insert(path);
        } 
        dfs(i, j+1, board, path, root);
        dfs(i, j-1, board, path, root);
        dfs(i-1, j, board, path, root);    
        dfs(i+1, j, board, path, root);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;;
        rows = board.size(); cols = board[0].size();
        visited = vector<vector<int>>(rows, vector<int>(cols, 0));
        t = new Trie();
        // insert words into Trie
        for(auto word : words)
        {
            t->insert(word);
        }
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                string path;
                dfs(i, j, board, path, t->root);
            }
        }
        return ans;
    }
};
