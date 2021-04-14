// https://leetcode-cn.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int times_max = 1, times_min = 1, best = INT_MIN;
        for(const auto& x:nums){
            int max_temp = times_max, min_temp = times_min;
            times_max = max(max(max_temp*x, x), min_temp*x);
            times_min = min(min(max_temp*x, x), min_temp*x);
            best = max(best, times_max);
        }
        return best;
    }
};