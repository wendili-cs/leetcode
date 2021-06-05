// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int XOR = 0;
        for(const int& num:nums) XOR ^= num;
        int index = XOR & (-XOR); // 得到最低位的1，这两个数的index的bit上是不一样的
        int res1 = 0, res2 = 0;
        for(const int& num:nums){
            if((num & index) == 0) res1 ^= num;
            else res2 ^= num;
        }
        return {res1, res2};
    }
};