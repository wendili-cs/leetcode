// https://leetcode.com/problems/find-closest-number-to-zero/

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        for(auto num:nums){
            if(abs(num) < abs(res)) res = num;
            else if(abs(num) == abs(res)) res = max(num, res);
        }
        return res;
    }
};