// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        // dp[i] = min([dp[j] + 1 for j in [0:i-1] if j + nums[j] >= dp[i]])
        vector<int> dp(nums.size(), 100000);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(j + nums[j] >= i){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};