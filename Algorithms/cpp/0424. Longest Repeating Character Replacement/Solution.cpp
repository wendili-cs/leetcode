// https://leetcode-cn.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> umap;
        int l = 0, maxCnt = 0, r;
        for(r = 0; r < s.length(); r++){
            umap[s[r]]++;
            maxCnt = max(maxCnt, umap[s[r]]);
            if(r - l + 1 - maxCnt > k){
                umap[s[l]]--;
                l++;
            }
        }
        return r - l;
    }
};