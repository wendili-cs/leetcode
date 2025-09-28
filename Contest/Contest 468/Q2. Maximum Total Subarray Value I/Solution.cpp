// https://leetcode.com/problems/maximum-total-subarray-value-i/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long minv = nums[0], maxv = nums[0];
        for(long num:nums) {
            minv = min(minv, num);
            maxv = max(maxv, num);
        }
        return k*(maxv - minv);
    }
};