// https://leetcode.com/problems/steps-to-make-array-non-decreasing/

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int len = nums.size(), res = 0;
        stack<int> stk;
        vector<int> dp(len, 0);
        for(int i = len - 1; i >= 0; i--){
            while(!stk.empty() && nums[i] > nums[stk.top()]){
                dp[i] = max(dp[i] + 1, dp[stk.top()]);
                res = max(res, dp[i]);
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};