// https://leetcode.com/problems/check-if-an-array-is-consecutive/

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i + nums[0] != nums[i]) return false;
        }
        return true;
    }
};