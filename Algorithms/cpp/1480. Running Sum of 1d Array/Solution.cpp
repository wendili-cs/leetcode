// https://leetcode-cn.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};