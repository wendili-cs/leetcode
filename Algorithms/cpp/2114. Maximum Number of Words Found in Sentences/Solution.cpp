// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for(string& str:sentences){
            int cur = 1;
            for(char& c:str){
                if(c == ' ') cur++;
            }
            res = max(res, cur);
        }
        return res;
    }
};