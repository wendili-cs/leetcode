// https://leetcode.com/problems/minimum-number-of-keypresses/

class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> cnt(26, 0);
        for(auto c:s){
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end());
        int res = 0;
        for(int i = 0; i < 26; i++){
            int idx = 25 - i;
            res += (i/9 + 1)*cnt[idx];
        }
        return res;
    }
};