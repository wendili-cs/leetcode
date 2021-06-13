// https://leetcode-cn.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int max_e = *max_element(nums.begin(), nums.end()), len = nums.size();
        vector<bool> dp(sum/2 + 1, false); // dp[s]是剩余s是否可能被分走
        function<void(int, int)> recur;
        recur = [&](int pos, int s) -> void {
            dp[s] = true;
            for(int i = pos; i < len && !dp[0]; i++)
                if(s - nums[i] >= 0 && !dp[s - nums[i]])
                    recur(i + 1, s - nums[i]);
        };
        recur(0, sum/2);
        return dp[0];
    }
};