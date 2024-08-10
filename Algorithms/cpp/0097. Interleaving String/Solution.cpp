// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if(m + n != s3.length()) return false;
        // dp[i][j]: if s1[:i] and s2[:j] can form s3[:i + j]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(s1.substr(0, i) == s3.substr(0, i)) dp[i][0] = true;
        }
        for(int j = 1; j <= n; j++){
            if(s2.substr(0, j) == s3.substr(0, j)) dp[0][j] = true;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] || 
                   dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp.back().back();
    }
};