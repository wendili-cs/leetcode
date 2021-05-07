// https://leetcode-cn.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> umap;
        int l = 0, res = 0, maxCnt = 0;
        for(int i = 0; i < s.length(); i++){
            umap[s[i]]++;
            maxCnt = max(maxCnt, umap[s[i]]);
            if(i - l + 1 - maxCnt > k){
                umap[s[l]]--;
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};