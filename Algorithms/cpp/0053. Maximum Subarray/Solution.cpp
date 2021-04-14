// https://leetcode-cn.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), best = INT_MIN, sums = 0;
        for(const auto& x:nums){
            sums = max(x, sums + x);
            best = max(sums, best);
        }
        return best;
    }
};