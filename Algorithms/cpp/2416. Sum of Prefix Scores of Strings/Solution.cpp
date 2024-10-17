// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

class Trie {
public:
    unordered_map<char, Trie*> children;
    string word;
    int score;
    Trie() {
        score = 0;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for(string& word:words){
            Trie* node = root;
            for(char& c:word){
                if(node->children.find(c) == node->children.end()){
                    node->children[c] = new Trie();
                }
                node->children[c]->score++;
                node = node->children[c];
            }
            node->word = word;
        }
        vector<int> res;
        for(string& word:words){
            Trie* node = root;
            int cnt = 0; // count scores for each word
            for(char& c:word){
                cnt += node->children[c]->score;
                node = node->children[c];
            }
            res.push_back(cnt);
        }
        return res;
    }
};