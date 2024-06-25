// https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/

class Solution {
public:
    int convertArray(vector<int>& nums) {
        int n = nums.size(), res, MAX = 10000000;
        auto calc_num_ops = [&]() -> int {
            vector<vector<int>> dp(n, vector<int>(1001, MAX));
            set<int> vals(nums.begin(), nums.end());
            // dp[i][val] means non-decreasing for nums[i], and nums[i]<=val
            // dp[i][val] = min(dp[i - 1][val2] + abs(val2 - nums[i])) for val2 in [0, val]
            int cur_min = MAX;
            for(int val:vals){
                cur_min = min(abs(nums[0] - val), cur_min);
                dp[0][val] = cur_min;
            }
            for(int i = 1; i < n; i++){
                int cur_min = MAX;
                for(int val:vals){
                    cur_min = min(cur_min, dp[i - 1][val] + abs(val - nums[i]));
                    dp[i][val] = cur_min;
                }
            }
            return dp.back()[*(vals.rbegin())];
        };
        res = calc_num_ops();
        reverse(nums.begin(), nums.end());
        res = min(res, calc_num_ops());
        return res;
    }
};