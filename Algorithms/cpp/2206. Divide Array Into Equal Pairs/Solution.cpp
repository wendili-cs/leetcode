// https://leetcode.com/problems/divide-array-into-equal-pairs/

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()/2; i++){
            if(nums[2*i] != nums[2*i + 1]) return false;
        }
        return true;
    }
};