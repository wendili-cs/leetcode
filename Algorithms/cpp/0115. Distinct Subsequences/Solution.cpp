// https://leetcode-cn.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if(len1 < len2 || (len1==len2 && s!=t)) return 0;
        else if(len1 == len2) return 1;
        vector<vector<long> > dp(len1 + 1, vector<long>(len2 + 1, 0));
        // dp[i][j]表示在s[i:]的子序列中t[j:]出现的个数。
        // dp[:][n] = 1, dp[m][:] = 0
        // s[i]==t[j]，dp[i][j] = dp[i+1][j+1] + dp[i][j] = dp[i+1][j]
        // s[i]!=y[j]，dp[i][j] = dp[i+1][j]
        for(int i = 0; i <= len1; i++) dp[i][len2] = 1;
        for(int i = len1 - 1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0; j--){
                if(s[i]==t[j]) dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                else dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};