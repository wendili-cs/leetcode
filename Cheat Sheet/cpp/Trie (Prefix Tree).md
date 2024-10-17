# 前缀树 Trie (Prefix Tree)
## 前缀树的代码

```c++
// 类定义
class Trie{
public:
    unordered_map<char, Trie*> children;
    string word; // 单词存这里
    Trie() {}
};

// 将一个单词列表的每个单词放入Trie
vector<string> words = {"aa", "ab", "abc", "abcd", "abcc"};
for(string& word:words){
    Trie* node = root;
    for(char& c:word){
        if(node->children.find(c) == node->children.end()){
            node->children[c] = new Trie();
        }
        node = node->children[c];
    }
    node->word = word;
}
```

