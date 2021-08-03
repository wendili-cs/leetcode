// https://leetcode-cn.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* search_prefix(string prefix) {
        Trie* node = this;
        for(auto c:prefix){
            if(!node->children[c - 'a']) return node->children[c - 'a'];
            node = node->children[c - 'a'];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie():children(26, nullptr), isEnd(false) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(auto c:word){
            if(!node->children[c - 'a']) node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = search_prefix(word);
        return node && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return search_prefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */