// https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/

class WordDictionary {
private:
    vector<WordDictionary*> children;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    WordDictionary():children(26), isEnd(false) {}
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(auto c:word){
            if(!node->children[c - 'a']) node->children[c - 'a'] = new WordDictionary();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        if(word.empty()) return this->isEnd;
        bool ret = false;
        if(word[0] == '.'){
            for(int i = 0; i < 26; i++){
                if(this->children[i]) ret |= this->children[i]->search(word.substr(1));
            }
        }
        else if(this->children[word[0] - 'a']) return this->children[word[0] - 'a']->search(word.substr(1));
        return ret;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */