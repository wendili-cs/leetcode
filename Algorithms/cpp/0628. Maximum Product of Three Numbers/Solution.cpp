// https://leetcode-cn.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0]*nums[1]*nums[len - 1], nums[len - 1]*nums[len - 2]*nums[len - 3]);
    }
};