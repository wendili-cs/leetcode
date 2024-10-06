// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int l = 1;
        for(int r = 1; r < nums.size(); r++){
            if(nums[r] != nums[l - 1]){
                swap(nums[l], nums[r]);
                l++;
            }
        }
        return l;
    }
};