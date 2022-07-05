// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int len1 = startWords.size(), len2 = targetWords.size(), res = 0;
        vector<int> sw(len1, 0);
        for(int i = 0; i < len1; i++){
            for(char& c:startWords[i]) sw[i] |= (1 << (c - 'a'));
        }
        sort(sw.begin(), sw.end());
        for(int i = 0; i < len2; i++){
            int cur = 0;
            for(char& c:targetWords[i]) cur |= (1 << (c - 'a'));
            for(int j = 0; j < 26; j++){
                if(cur & (1 << j)){
                    int ori = cur^(1 << j);
                    int idx = lower_bound(sw.begin(), sw.end(), ori) - sw.begin();
                    if(idx < sw.size() && sw[idx] == ori){
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};