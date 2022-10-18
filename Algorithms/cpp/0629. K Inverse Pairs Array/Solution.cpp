// https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000007;
        // 1. dp[:][0] = 1 only one arrangement for any n
        // 2. dp[n][k] = sum_{x = 0}^{min(n - 1, k)} dp[n - 1][k - x]
        // 3. modify dp, now dp[i][j] = sum(dp[i][:j])
        // vector<vector<long>>dp(n + 1, vector<long>(k + 1, 0));
        vector<long> dp(k + 1, 0);
        for(int i = 1; i <= n; i++){
            // next round dp (equals to dp[i]), 
            // while old dp equals to dp[i - 1]
            vector<long> ndp(k + 1, 0);
            for(int j = 0; j <= k; j++){
                if(j == 0) ndp[j] = 1;
                else{
                    ndp[j] = dp[j];
                    if(j - i >= 0) ndp[j] -= dp[j - i];
                    ndp[j] += ndp[j - 1];
                    ndp[j] %= M;
                }
            }
            dp = move(ndp);
        }
        return (dp[k] + M - (k > 0 ? dp[k - 1] : 0))%M;
    }
};