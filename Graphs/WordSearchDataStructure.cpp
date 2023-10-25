// LC211 - TODO
class TrieNode
{
    public:
        unordered_map<char, TriedNode*> children;
        bool endOfWord = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }
        }
    }
    
    bool search(string word) {
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
