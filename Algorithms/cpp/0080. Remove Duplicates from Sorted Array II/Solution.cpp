// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int i = 0;
        for(int num:nums){
            if(i < 2 || nums[i - 2] != num) nums[i++] = num;
        }
        return i;
    }
};