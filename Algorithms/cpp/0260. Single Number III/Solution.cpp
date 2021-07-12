// https://leetcode-cn.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a_xor_b = 0, a = 0, b = 0, low_bit = 1;
        for(int& num:nums) a_xor_b ^= num;
        while((a_xor_b & 1)==0){ // 不要用x&(-x)，会跳到负数导致问题
            low_bit <<= 1;
            a_xor_b >>= 1;
        }
        for(int& num:nums) 
            if((num & low_bit) == 0) a ^= num;
            else b ^= num;
        return {a, b};
    }
};