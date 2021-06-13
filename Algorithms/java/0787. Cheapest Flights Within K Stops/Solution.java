// https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] dp = new int[n][k + 2]; // dp[i][k]表示经过k个中转站后到达站i的最低费用
        for(int i = 0; i < n; i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
        for(int i = 0; i < k + 2; i++) dp[src][i] = 0;
        for(int i = 1; i < k + 2; i++){
            for(int[] flight:flights){
                if(dp[flight[0]][i - 1] != Integer.MAX_VALUE)
                    dp[flight[1]][i] = Math.min(dp[flight[1]][i], flight[2] + dp[flight[0]][i - 1]);
            }
        }
        return dp[dst][k + 1] == Integer.MAX_VALUE? -1:dp[dst][k + 1];
    }
}