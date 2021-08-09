// https://leetcode-cn.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(int& num:nums){
            if(num == 0) return 0;
            else if(num < 0) res *= -1;
        }
        return res;
    }
};