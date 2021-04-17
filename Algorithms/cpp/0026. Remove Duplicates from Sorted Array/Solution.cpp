// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0; // 新的无重复元素的指针
        int len = nums.size();
        if(len==0||len==1){
            return len;
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[idx] != nums[i]){
                nums[idx+1] = nums[i];
                idx += 1;
            }
        }
        return idx + 1;
    }
};