// https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/

class Solution {
public:
    vector<double> dicesProbability(int n) {
        // 通项公式：f(n,s)=f(n-1,s-1)+f(n-1,s-2)+f(n-1,s-3)+f(n-1,s-4)+f(n-1,s-5)+f(n-1,s-6)
        vector<vector<int> > dp(2, vector<int>(6*n + 1, 0));
        for(int i = 1; i <= 6; i++) dp[1][i] = 1;
        for(int i = 2; i <= n; i++){
            fill(dp[i%2].begin(), dp[i%2].end(), 0);
            for(int j = i; j <= 6*n; j++){
                for(int t = 1; t <= 6; t++){
                    dp[i%2][j] += t>=j?0:dp[(i - 1)%2][j - t];
                }
            }
        }
        double sum = accumulate(dp[n%2].begin(), dp[n%2].end(), 0);
        vector<double> res(5*n + 1);
        for(int i = 0; i < 5*n + 1; i++){
            res[i] = dp[n%2][i + n]/sum;
        }
        return res;
    }
};