// https://leetcode-cn.com/problems/edit-distance/
// DP核心：当前w1[i]和w2[j]相同，dp[i][j]==dp[i-1][j-1]

class Solution {
public:
    int minDistance(string word1, string word2) {
        int MAX_OPS = 1000;
        int len1 = word1.length(), len2 = word2.length();
        if(len1 == 0 || len2 == 0){
            return len1 == 0 ? len2 : len1;
        }
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, MAX_OPS));
        for(int i = 0; i <= len1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= len2; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                int l = dp[i - 1][j];
                int d = dp[i][j - 1];
                int ld = dp[i - 1][j - 1];
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 1 + min(min(l, d), ld - 1);
                }
                else{
                    dp[i][j] = 1 + min(min(l, d), ld);
                }
            }
        }
        return dp[len1][len2];
    }
};