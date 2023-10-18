/*
LC208 - Implement Trie
Search complexity O(n), where n is the length of 
the string
Insertion complexity - O(nlogm), where n is
the length of the string and m is the number of keys in the tree
*/

class TrieNode
{
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        // iterate through every single character
        // in the word and place inside tree. 
        for(char c : word)
        {
            // if the current node does not have any children
            // starting with c create a new child starting with c
            if(curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        // last character marks end of word
        curr->endOfWord = true;
    }
    
    bool search(string word)
    {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }      
    
    bool startsWith(string prefix) {
        // same logic as search
        // but don't check for end of word
        // condition
        TrieNode* curr = root;
        for(char c : prefix)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
