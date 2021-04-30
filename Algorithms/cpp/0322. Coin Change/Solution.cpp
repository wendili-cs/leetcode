// https://leetcode-cn.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        int MAX_VAL = 20000;
        vector<int> dp(amount + 1, MAX_VAL);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < len; j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == MAX_VAL? -1:dp[amount];
    }
};