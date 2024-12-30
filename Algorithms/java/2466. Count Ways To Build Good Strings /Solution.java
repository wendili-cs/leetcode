// https://leetcode.com/problems/count-ways-to-build-good-strings/

class Solution {
    public int countGoodStrings(int low, int high, int zero, int one) {
        int M = 1000000007, res = 0;
        int[] dp = new int[high + 1];
        dp[0] = 1;
        for(int i = 1; i <= high; i++){
            dp[i] = (i - zero >= 0 ? dp[i - zero] : 0) + (i - one >= 0 ? dp[i - one] : 0);
            dp[i] %= M;
        }
        for(int i = low; i <= high; i++){
            res = (res + dp[i])%M;
        }
        return res;
    }
}