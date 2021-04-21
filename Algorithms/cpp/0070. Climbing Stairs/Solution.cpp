// https://leetcode-cn.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(50, -1);
        if(n <= 2){
            return n;
        }
        dp[n - 1] = 1;
        dp[n - 2] = 2;
        function<int(int)> recurr;
        recurr = [&](int from) -> int {
            if(from >= n){
                return 0;
            }
            else{
                if(dp[from] == -1){
                    dp[from] = recurr(from + 1) + recurr(from + 2);
                }
                return dp[from];
            }
        };
        return recurr(0);
    }
};