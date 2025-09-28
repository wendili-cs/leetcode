// https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 0) {
                res |= nums[i];
            }
        }
        return res;
    }
};=