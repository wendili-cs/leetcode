// https://leetcode-cn.com/problems/maximum-average-subarray-i/

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int len = nums.length, res = Integer.MIN_VALUE;
        for(int i = 1; i < len; i++) nums[i] += nums[i - 1];
        for(int i = k - 1; i < len; i++) res = Math.max(res, i==k-1?nums[i]:nums[i] - nums[i - k]);
        return (double)res / k;
    }
}