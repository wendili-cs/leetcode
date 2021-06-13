// https://leetcode-cn.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, max_e = 0, len = nums.size();
        for(int i = 0; i < len; i++){
            sum += nums[i];
            max_e = max(max_e, nums[i]);
        }
        if(sum & 1) return false;
        vector<vector<bool> > dp(len, vector<bool>(sum/2 + 1, false));
        // dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i]]
        for(int i = 0; i < len; i++){
            for(int s = 0; s <= sum/2; s++){
                if(i == 0) dp[i][s] = (nums[i] == s);
                else dp[i][s] = dp[i - 1][s] || (s - nums[i] >= 0? dp[i - 1][s - nums[i]]:false);
            }
        }
        return dp.back().back();
    }
};