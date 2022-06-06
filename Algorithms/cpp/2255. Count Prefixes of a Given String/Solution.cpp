// https://leetcode.com/problems/count-prefixes-of-a-given-string/

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for(int i = 0; i < words.size(); i++){
            if(words[i].length() > s.length()) continue;
            for(int j = 0; j < words[i].length(); j++){
                if(words[i][j] != s[j]) break;
                else if(j == words[i].length() - 1) res++;
            }
        }
        return res;
    }
};