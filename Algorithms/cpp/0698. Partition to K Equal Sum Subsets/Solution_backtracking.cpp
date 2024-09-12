// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, size = nums.size();
        for(int num:nums) sum += num;
        if(sum % k != 0) return false;
        int target = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> visited(size, false);
        function<bool(int, int, int)> recur;
        recur = [&](int num_idx, int bucket_idx, int cur_sum) -> bool {
            // given number idx, bucket idx and current sum, if we can solve it
            if(bucket_idx == k) return true;
            if(cur_sum == target) return recur(0, bucket_idx + 1, 0); // start from next bucket, num_idx set to 0
            for(int i = num_idx; i < size; i++){
                if(!visited[i] && nums[i] + cur_sum <= target){
                    visited[i] = true;
                    if(recur(i + 1, bucket_idx, cur_sum + nums[i])) return true;
                    visited[i] = false;
                    // optimization: if we start with cur_sum = 0 and we cannot form a solution, 
                    // it means the there is no solution in current situation
                    if(cur_sum == 0) return false;
                }
            }
            return false;
        };
        return recur(0, 0, 0);
    }
};