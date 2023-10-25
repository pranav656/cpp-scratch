// LC211 - Design Add and Search Words Data Structure
// Implement with Trie
// Same as a trie implementation, expect
// for words where patterns have to be searched. For words where
// you have . then the search complexity is O(n^2)
class TrieNode
{
    public:
        unordered_map<char, TrieNode*> children;
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
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }

    // helper function to recursively search for patterns
    bool wordSearch(string word, TrieNode* root, int idx)
    {
        if(idx == word.size()) return root->endOfWord;
        TrieNode* node = root;
        char c = word[idx];
        if(c == '.') {
            for(char c= 'a'; c <= 'z'; c++)
            {
                if(node->children.find(c) != node->children.end())
                {
                    bool found = wordSearch(word, node->children[c], idx+1);
                    if(found) return true;
                }
            }
            return false;
        }
        else
        {
            if(node->children.find(c) == node->children.end()) return false;
            return wordSearch(word, node->children[c], idx+1);
        }
    }
    bool search(string word) {
        return wordSearch(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
