// https://leetcode-cn.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l1 = -1, l2 = -1; // l1及其左边都小于1，l2及其左边都小于2
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 2){
                l2++;
                swap(nums[l2], nums[i]);
                if(nums[l2] < 1){
                    l1++;
                    swap(nums[l1], nums[l2]);
                }
            }
        }
    }
};