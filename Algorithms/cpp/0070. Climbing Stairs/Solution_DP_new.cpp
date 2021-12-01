// https://leetcode.com/problems/climbing-stairs/

class Solution {
private:
    vector<int> dp = vector<int>(46, -1);
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(dp[n] == -1){
            dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return dp[n];
    }
};