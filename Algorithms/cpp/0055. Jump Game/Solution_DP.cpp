// https://leetcode-cn.com/problems/jump-game/
// https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && nums[j] + j >= i) dp[i] = true;
            }
        }
        return dp.back();
    }
};