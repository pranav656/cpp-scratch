// LC588 - Design In-Memory File system
// Practical applications:
// Embedded Systems
// File system simulators
// Data Processing applications where disk I/O is expensive
class FileSystem {
private:
    struct fileNode {
        // this structure contains the list 
        // of files/folders in the current fileNode
        // FileNode can either be a file or a
        // folder
        unordered_map<string, fileNode*> next;
        bool isFile;
        string content;
        fileNode() :isFile(false), content("") {}
    };

    fileNode *root;

    // creates a path if it does not already exist
    fileNode* goToPath(string path) {
        fileNode* curr = root;
        stringstream s (path);
        string folder;
        while(getline(s, folder, '/')) {
            if(folder.size()) {
                if(curr->next[folder] == nullptr)
                    curr->next[folder] = new fileNode();
                curr = curr->next[folder];
            }
        }
        return curr;
    }
public:
    FileSystem() {
        root = new fileNode();
    }
    
    vector<string> ls(string path) {
        fileNode* curr = goToPath(path);
        if(curr->isFile) {
            return {path.substr(path.find_last_of('/')+1)};
        }
        vector<string> res;
        for(auto&f : curr->next) {
            res.push_back(f.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) {
        fileNode *curr = goToPath(path);
    }
    
    void addContentToFile(string filePath, string content) {
        fileNode* curr = goToPath(filePath);
        curr->content += content;
        curr->isFile = true;
    }
    
    string readContentFromFile(string filePath) {
        fileNode* curr = goToPath(filePath);
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
