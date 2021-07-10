// https://leetcode-cn.com/problems/strange-printer/

class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
        // dp[i][j] 表示s[i]到s[j]需要的最小打印次数
        // dp[i][j] = 1 + dp[i+1][j]
        // if(s[i]==s[k]) dp[i][j] = dp[i][k-1] + dp[k+1][j]
        for(int len = 1; len <= s.length(); len++){
            for(int l = 0; l + len - 1 < s.length(); l++){
                int r = l + len - 1;
                dp[l][r] = 1 + (l==r?0:dp[l + 1][r]);
                for(int k = l + 1; k <= r; k++){
                    if(s[l] == s[k]) dp[l][r] = min(dp[l][r], dp[l][k - 1] + (k==r?0:dp[k + 1][r]));
                }
            }
        }
        return dp[0][s.length() - 1];
    }
};