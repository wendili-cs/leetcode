// https://leetcode-cn.com/problems/ones-and-zeroes/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int MAX_V = 1000, res = 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        // dp[m][n] = max(dp[m][n], dp[m - c1][n - c0] + 1)
        for(string& str:strs){ // 先物品
            vector<int> cnt(2, 0);
            for(char& c:str) cnt[c - '0']++;
            for(int i = m; i >= cnt[0]; i--){
                for(int j = n; j >= cnt[1]; j--){
                    dp[i][j] = max(dp[i][j], dp[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }
        return dp.back().back();
    }
};