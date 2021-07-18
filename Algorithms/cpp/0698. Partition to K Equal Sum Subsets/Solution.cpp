// https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        sort(nums.begin(), nums.end());
        int target = sum/k, size = 1 << nums.size();
        if(nums.back() > target) return false;
        vector<bool> dp(size, false);
        dp[0] = true;
        vector<int> sums(size);
        for(int i = 0; i < size; i++){ // bin(i)是一个对每一个元素是否添加的组合
            if(!dp[i]) continue; // dp[i] 表示当前的配置是否可行
            for(int j = 0; j < nums.size(); j++){
                // 先检查nums[j]是否已包含入内
                if(i & (1 << j) != 0) continue;
                int next = i | (1 << j); // 添加了nums[j]之后的配置
                if(dp[next]) continue; // 这种情况已经考虑过
                if(sums[i]%target + nums[j] <= target){
                    dp[next] = true;
                    sums[next] = sums[i] + nums[j];
                }
                else break; // 不用考虑更大的nums[j]了
            }
        }
        return dp.back();
    }
};