// https://leetcode.com/problems/sentence-screen-fitting/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int word_cnt = 0, len = sentence.size();
        map<int,int> m; // m[i] means: sentence[i] begins, how many word can be placed in one row
        for(int i = rows; i > 0; i--){
            int start_idx = word_cnt%len;
            if(m.find(start_idx) == m.end()){
                int lcnt = 0, wcnt = 0;
                for(int j = start_idx; lcnt + sentence[j%len].size() <= cols; j++){
                    lcnt += sentence[j%len].size() + 1;
                    wcnt++;
                }
                m[start_idx] = wcnt;
            }
            word_cnt += m[start_idx];
        }
        return word_cnt/len;
    }
};