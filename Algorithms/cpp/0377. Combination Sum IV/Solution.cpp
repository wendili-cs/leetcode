// https://leetcode-cn.com/problems/combination-sum-iv/

// 需要一个动态规划
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0, len = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        dp[0] = 1;
        function<int(int)> recur;
        recur = [&](int remain) -> int {
            if(remain < 0) return 0;
            else if(dp.find(remain) != dp.end()){
                return dp[remain];
            }
            int ret = 0;
            for(int pos = 0;pos < len; pos++){
                ret += recur(remain - nums[pos]);
            }
            dp[remain] = ret;
            return dp[remain];
        };
        
        return recur(target);
    }
};