// https://leetcode-cn.com/problems/most-common-word/

class Solution {
public:
    void to_lower(string& str) {
        for(char& c:str){
            if('A' <= c && c <= 'Z') c += 'a' - 'A';
        }
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s;
        for(auto& word:banned) s.insert(word);
        map<string, int> cnter;
        int l = 0, most_freq = 0;
        string res;
        for(int r = 0; r < paragraph.length(); r++){
            if(!isalpha(paragraph[r]) || r == paragraph.length() - 1){
                if(isalpha(paragraph[l])){
                    string word = paragraph.substr(l, (!isalpha(paragraph[r])?r - l:r - l + 1));
                    to_lower(word);
                    if(s.find(word) == s.end()) cnter[word]++;
                    if(most_freq < cnter[word]){
                        most_freq = cnter[word];
                        res = word;
                    }
                }
                l = r + 1;
            }
        }
        return res;
    }
};