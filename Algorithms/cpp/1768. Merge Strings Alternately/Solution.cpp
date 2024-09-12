// https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx1 = 0, idx2 = 0;
        string res;
        while(idx1 < word1.length() || idx2 < word2.length()){
            if(idx1 < word1.length()){
                res.push_back(word1[idx1++]);
            }
            if(idx2 < word2.length()){
                res.push_back(word2[idx2++]);
            }
        }
        return res;
    }
};