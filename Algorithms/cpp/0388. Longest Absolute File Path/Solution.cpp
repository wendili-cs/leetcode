// https://leetcode.com/problems/longest-absolute-file-path/

class FTries {
public:
    map<string, FTries*> sub;
    string name;
    bool is_file;
    int level, path_len;
    FTries *parent;
    FTries(string _name, int _level, FTries *_parent) {
        name = _name;
        check_file();
        level = _level;
        parent = _parent;
        if(parent) path_len = parent->path_len;
        else path_len = 0;
        path_len += name.length() + 1;
    }
    void check_file(){
        if(name.find('.') != name.npos) is_file = true;
        else is_file = false;
    }
};


class Solution {
public:
    int get_longest_len(FTries *node) {
        if(node->is_file) return node->path_len;
        else if(node->sub.empty()) return 0;
        int max_len = 0;
        for(auto it = node->sub.begin(); it != node->sub.end(); it++){
            max_len = max(get_longest_len(it->second), max_len);
        }
        return max_len;
    };
    
    int lengthLongestPath(string input) {
        int l = 0, r;
        FTries *root = new FTries("", -1, nullptr), *cur = root, *next;
        string path;
        while(true){
            r = input.find('\n', l);
            path = input.substr(l, (r == input.npos?10000:r-l));
            // process path
            int cnt = 0;
            for(int i = 0; i < path.length() && path[i]=='\t'; i++) cnt++;
            string file_name = path.substr(cnt);
            while(cnt <= cur->level) cur = cur->parent;
            cur->sub[file_name] = new FTries(file_name, cnt, cur);
            cur = cur->sub[file_name];
            l = r + 1;
            if(r == input.npos) break;
        }
        int res = get_longest_len(root);
        return res==0?0:res-2;
        
    }
};