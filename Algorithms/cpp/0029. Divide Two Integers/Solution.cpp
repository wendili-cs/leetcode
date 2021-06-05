// https://leetcode-cn.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long res = 0, up = abs(dividend), down = abs(divisor);
        while(up >= down){
            long cur = 1, base = down;
            while(up > (base << 1)){
                cur <<= 1;
                base <<= 1;
            }
            res += cur;
            up -= base;
        }
        bool sign = (dividend ^ divisor) >= 0;
        res = sign? res:-res;
        return (res > INT_MAX || res < INT_MIN) ? INT_MAX : res;
    }
};