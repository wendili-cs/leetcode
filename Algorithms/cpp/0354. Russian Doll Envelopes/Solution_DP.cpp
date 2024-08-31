// https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size(), res = 1;
        sort(envelopes.begin(), envelopes.end(), cmp);
        // dp[i]: max length of the increasing subsequence with first i elements
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(envelopes[j][1] > envelopes[i][1]){
                    dp[j] = max(dp[j], dp[i] + 1);
                    res = max(res, dp[j]);
                }
            }
        }
        return res;
    }
};