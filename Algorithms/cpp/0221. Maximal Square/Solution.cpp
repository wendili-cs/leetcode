// https://leetcode-cn.com/problems/maximal-square/
// https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), max_len = 0;
        // dp[i][j]: 到(i, j)为止最大的正方形边长
        // dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    dp[i + 1][j + 1] = 1 + min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1]));
                    max_len = max(max_len, dp[i + 1][j + 1]);
                }
            }
        }
        return max_len*max_len;
    }
};