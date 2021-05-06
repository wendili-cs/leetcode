// https://leetcode-cn.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return true;
        vector<int> dp(len);
        dp[0] = nums[0];
        for(int i = 1; i < len; i++){
            if(dp[i - 1] >= i){
                dp[i] = max(dp[i - 1], i + nums[i]);
            }
            if(dp[i] >= len - 1) return true;
        }
        return false;
    }
};