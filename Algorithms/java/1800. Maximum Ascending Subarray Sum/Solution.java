// https://leetcode.com/problems/maximum-ascending-subarray-sum

class Solution {
    public int maxAscendingSum(int[] nums) {
        int res = 0, curSum = 0;
        for(int i = 0; i < nums.length; i++){
            if(i > 0 && nums[i] <= nums[i - 1]){
                res = res > curSum ? res : curSum;
                curSum = 0;
            }
            curSum += nums[i];
        }
        res = res > curSum ? res : curSum;
        return res;
    }
}