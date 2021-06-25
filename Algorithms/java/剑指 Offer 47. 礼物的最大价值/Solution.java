// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/

class Solution {
    public int maxValue(int[][] grid) {
        int m = grid.length, n = grid[0].length, res = grid[0][0];
        int [][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            res = Math.max(res, dp[i][0]);
        }
        for(int j = 1; j < n; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
            res = Math.max(res, dp[0][j]);
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                res = Math.max(res, dp[i][j]);
            }
        }
        return res;
    }
}