// https://leetcode-cn.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, z = x ^ y;
        for(int i = 0; i < 31; i++){
            res += z&1;
            z >>= 1;
        }
        return res;
    }
};