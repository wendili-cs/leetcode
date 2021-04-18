// https://leetcode-cn.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(auto&& num:nums){
            if(num <= 0){
                num = len + 1; // 去掉所有负数
            }
        }
        for(int i = 0; i < len; i++){
            int num = abs(nums[i]);
            if(num <= len){
                nums[num-1] = -abs(nums[num-1]); // 对应的index的值设置为负数，一表两用
            }
        }
        for(int i = 0; i < len; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return len + 1;
    }
};