// https://leetcode-cn.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
        int max_sq = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i - 1][j - 1] == '1')
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
                max_sq = max(max_sq, dp[i][j]);
            }
        }
        return max_sq*max_sq;
    }
};