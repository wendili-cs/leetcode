// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        function<int(int)> recur;
        recur = [&](int x) -> int {
            if(x <= 1) return 0;
            if(dp[x] == -1){
                dp[x] = min(recur(x - 1) + cost[x - 1], recur(x - 2) + cost[x - 2]);
            }
            return dp[x];
        };
        return recur(n);
    }
};