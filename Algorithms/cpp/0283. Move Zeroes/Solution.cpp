// https://leetcode-cn.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int idx = 0;
        for(int i = 0; i < len; i++){
            if(nums[i]){
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
    }
};