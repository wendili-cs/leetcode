// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // dp[i] = dp[i - 1] + max(0, target[i] - target[i - 1]);
        // vector<int> dp(target.size());
        // dp[0] = target[0];
        int dp = target[0]; // use a integer rather than an array
        for(int i = 1; i < target.size(); i++){
            dp = dp + max(0, target[i] - target[i - 1]);
        }
        return dp;
    }
};