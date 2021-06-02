// https://leetcode-cn.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(len, 1);
        for(int i = 1; i < len; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i]%nums[j]==0){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> res = {nums[idx]};
        // int count = dp[idx];
        for(int i = idx - 1; i >= 0; i--){
            if(res.back()%nums[i]==0 && dp[i] == dp[idx] - res.size()){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};