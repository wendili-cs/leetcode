// https://leetcode.com/problems/longest-ideal-subsequence/

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for(char c:s){
            int idx = c - 'a', l = max(0, idx - k), r = min(25, idx + k), ldp = 0;
            for(int i = l; i <= r; i++){
                ldp = max(ldp, dp[i]);
            }
            dp[idx] = max(dp[idx], ldp + 1);
        }
        int res = 0;
        for(int num:dp){
            res = max(res, num);
        }
        return res;
    }
};