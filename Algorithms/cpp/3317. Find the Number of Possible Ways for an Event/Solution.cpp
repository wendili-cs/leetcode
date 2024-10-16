// https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/

class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        long mod = 1000000007;
        // dp[i][j]: 把i个performer分配到j个stage，每个场地至少1人
        int len = max(n, x) + 1; // dp的size
        vector<vector<long>> dp(len, vector<long>(len, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = (dp[i - 1][j - 1] + j*dp[i - 1][j])%mod;
            }
        }
        // 对于固定t个stage，方案数量：A^t_x * y^t * dp[n][t]
        // [x个stage里面挑出t个]*[这t个stage每个打分1-y]*[把n个performer分配到t个stage]
        long atx = 1, yt = 1, res = 0;
        for(int t = 1; t <= min(n, x); t++){
            atx = (atx * (x + 1 - t))%mod;
            yt = (yt*y)%mod;
            res = (res + (((atx*yt)%mod)*dp[n][t])) %mod;
        }
        return res;
    }
};