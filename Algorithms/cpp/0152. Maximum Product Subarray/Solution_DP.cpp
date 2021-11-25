// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], n = nums.size();
        vector<int> dp_min(n), dp_max(n);
        dp_min[0] = nums[0];
        dp_max[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int cur_max = max(nums[i], max(dp_min[i-1]*nums[i], dp_max[i-1]*nums[i]));
            int cur_min = min(nums[i], min(dp_min[i-1]*nums[i], dp_max[i-1]*nums[i]));
            dp_max[i] = cur_max;
            dp_min[i] = cur_min;
            res = max(cur_max, res);
        }
        return res;
        
    }
};