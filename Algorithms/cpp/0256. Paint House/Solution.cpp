// https://leetcode.com/problems/paint-house/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(3, 1e9));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(j != k){
                        dp[i][j] = min((i > 0 ? dp[i - 1][k] : 0) + costs[i][j], dp[i][j]);
                    }
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};