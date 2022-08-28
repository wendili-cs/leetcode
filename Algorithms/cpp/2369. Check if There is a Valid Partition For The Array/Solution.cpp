// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        // dp[i]: the subarray of nums[:i] have a valid parition
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        dp[1] = false;
        for(int i = 1; i < n; i++){
            bool con1 = dp[i - 1] && nums[i - 1] == nums[i];
            bool con2 = i > 1 && dp[i - 2] && nums[i - 2] == nums[i] && nums[i - 1] == nums[i];
            bool con3 = i > 1 && dp[i - 2] && nums[i - 2] == nums[i] - 2 && nums[i - 1] == nums[i] - 1;
            dp[i + 1] = con1 || con2 || con3;
        }
        return dp.back();
    }
};