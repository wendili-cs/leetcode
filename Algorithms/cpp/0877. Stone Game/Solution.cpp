// https://leetcode-cn.com/problems/stone-game/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // return true;
        int len = piles.size();
        vector<vector<int> >dp(len + 1, vector<int>(len + 1)); // 第i到第j个之间先手可以领先的最大值。
        for(int i = 0; i < len; i++) dp[i + 1][i + 1];
        for(int l = 1; l <= len; l++){
            for(int i = 0; i + l < len; i++){
                int j = i + l;
                // 先手选取i或者选取j，则形式颠倒
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[1][len] >= 0;
    }
};