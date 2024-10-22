// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int &num:nums){
            x ^= num;
        }
        for(int i = 0; i <= nums.size(); i++){
            x ^= i;
        }
        return x;
    }
};