// https://leetcode-cn.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= n; j++){
            if(p[j - 1] == '*') dp[0][j] = true;
            else break;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(isalpha(p[j - 1])){
                    dp[i][j] = p[j - 1]==s[i - 1] && dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};