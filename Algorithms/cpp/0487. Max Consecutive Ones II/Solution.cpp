// https://leetcode-cn.com/problems/max-consecutive-ones-ii/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size(), res = 0;
        if(len == 1) return 1;
        for(int i = 0; i < len - 1; i++){
            if(nums[i + 1] != 0){
                nums[i + 1] += nums[i];
                res = max(res, nums[i + 1]);
            }
        }
        for(int i = len - 1; i >= 0; i--){
            if(nums[i] != 0 && i < len - 1 && nums[i + 1] != 0) nums[i] = nums[i + 1];
            if(nums[i] == 0) res = max(res, (i==0?0:nums[i - 1]) + 1 + (i == len - 1?0:nums[i + 1]));
        }
        return res;
    }
};