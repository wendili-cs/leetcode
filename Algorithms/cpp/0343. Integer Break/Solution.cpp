// https://leetcode-cn.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n - 1;
        return n%3!=1? pow(3, n/3)*(max(n%3, 1)):pow(3, n/3-1)*4;
    }
};