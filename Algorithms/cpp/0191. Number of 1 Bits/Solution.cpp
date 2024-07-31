// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n > 0){
            if(n & 1) res++;
            n >>= 1;
        }
        return res;
    }
};