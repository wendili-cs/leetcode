// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[p[i]][s[j]]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 0; i < n; i++){
            if(p[i] != '*') break;
            if(i == n - 1) return true;
        }
        if(p == "*" || s == p) return true;
        if(s.empty() || p.empty()) return false;
        for(int i = 1; i < n + 1; i++){
            if(p[i - 1] == '*'){
                for(int j = 0; j < m + 1; j++){
                    dp[i][j] = dp[i][j] || dp[i - 1][j] || (j==0?false:dp[i][j - 1]);
                }
            }
            else if(p[i - 1] == '?'){
                for(int j = 1; j < m + 1; j++){
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
            else{
                for(int j = 1; j < m + 1; j++){
                    dp[i][j] = (p[i - 1]==s[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        bool res = dp[n][m];
        return res;
    }
};