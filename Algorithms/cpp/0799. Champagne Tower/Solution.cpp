// https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));
        dp[0][0] = (double)poured;
        for(int i = 1; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                dp[i][j] = max(0.0, (dp[i - 1][j] - 1)/2.0) + ((j > 0) ? max(0.0, (dp[i - 1][j - 1] - 1)/2.0) : 0.0);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return min(1.0, dp.back()[query_glass]);
    }
};