// https://leetcode.com/problems/design-in-memory-file-system/description/

class FileSystem {
public:
    struct TrieObj {
        bool isFolder;
        string content;
        map<string, TrieObj*> sub;
        TrieObj(): isFolder(true),content(""){}
    };

    TrieObj* root;
    
    FileSystem() {
        root = new TrieObj();
    }
    
    vector<string> ls(string path) {
        vector<string> ret;
        TrieObj* pos = resolve(path);
        if(pos->isFolder){
            for(auto s:pos->sub){
                ret.push_back(s.first);
            }
        }
        else{
            ret = {path.substr(path.find_last_of('/') + 1)}; // only the file name
        }
        return ret;
    }
    
    void mkdir(string path) {
        resolve(path);
    }
    
    void addContentToFile(string filePath, string content) {
        TrieObj* pos = resolve(filePath);
        pos->isFolder = false;
        pos->content = pos->content + content;
    }
    
    string readContentFromFile(string filePath) {
        TrieObj* pos = resolve(filePath);
        return pos->content;
    }

    TrieObj* resolve(string path) {
        stringstream ss(path);
        TrieObj* obj = root;
        string name;
        while(getline(ss, name, '/')){
            if(obj->sub.find(name) == (obj->sub).end()){ // empty case, create a folder
                obj->sub[name] = new TrieObj();
            }
            obj = obj->sub[name];
        }
        return obj;
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