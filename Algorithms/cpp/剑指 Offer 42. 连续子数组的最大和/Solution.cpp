// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        for(int i = 1; i < len; i++){
            nums[i] += max(nums[i - 1], 0);
        }
        return *max_element(nums.begin(), nums.end());
    }
};