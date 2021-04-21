// https://leetcode-cn.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return 0;
        }
        int STEP_MAX = 1001;
        vector<int> dp(STEP_MAX, STEP_MAX);
        for(int i = 0; i < len - 1; i++){
            if(nums[i] + i >= len - 1){
                dp[i] = 1;
            }
        }
        function<int(int)> recurr;
        recurr = [&](int pos) -> int {
            if(pos >= len - 1){
                return 0;
            }
            else{
                if(dp[pos] == STEP_MAX){
                    int min_step = STEP_MAX;
                    for(int j = 1; j <= nums[pos]; j++){
                        min_step = min(min_step, 1 + recurr(pos + j));
                    }
                    dp[pos] = min_step;
                }
                return dp[pos];
            }
        };
        return recurr(0);
    }
};