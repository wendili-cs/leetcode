// https://leetcode.com/problems/search-suggestions-system/

class PrefixTree {
public:
    map<char, PrefixTree*> children;
    bool is_leaf = false;
    string word;
    void add_str(string s) {
        if(!children[s[0]]) children[s[0]] = new PrefixTree();
        children[s[0]]->add_str(s.substr(1), s);
    }
    void add_str(string s, string ori_s) {
        if(s.empty()){
            is_leaf = true;
            word = ori_s;
        }
        else{
            if(!children[s[0]]) children[s[0]] = new PrefixTree();
            children[s[0]]->add_str(s.substr(1), ori_s);
        }
    }
    PrefixTree* find_node(string pre){
        if(pre.empty()) return this;
        return children[pre[0]]->find_node(pre.substr(1));
    }
};

class Solution {
public:
    void get_top3(PrefixTree* node, vector<string> &arr) {
        if(arr.size() == 3) return;
        if(node->is_leaf) arr.push_back(node->word);
        for(auto it:node->children){
            string debug = it.second->word;
            get_top3(it.second, arr);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        PrefixTree *root = new PrefixTree(), *cur = root;
        for(string& product:products){
            root->add_str(product);
        }
        
        vector<vector<string>>res;
        for(int i = 0; i < searchWord.length(); i++){
            vector<string> temp;
            if(cur) cur = cur->children[searchWord[i]];
            if(cur) get_top3(cur, temp);
            res.push_back(temp);
        }
        return res;
    }
};