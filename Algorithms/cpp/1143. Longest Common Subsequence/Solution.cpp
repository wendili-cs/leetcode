// https://leetcode-cn.com/problems/longest-common-subsequence/
// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 这里dp[i][j]定义为以text1中第i个char和text2中第j个char为相同元素的最长子字符串
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};