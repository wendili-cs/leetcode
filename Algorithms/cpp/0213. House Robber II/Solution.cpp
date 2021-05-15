// https://leetcode-cn.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return *max_element(nums.begin(), nums.end());
        int res = 0, temp = 0;
        vector<int> dp(len, 0);
        dp[1] = nums[1];
        for(int i = 2; i < len; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        res = dp[len - 1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len - 1; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        res = max(dp[len - 2], res);
        return res;
    }
};