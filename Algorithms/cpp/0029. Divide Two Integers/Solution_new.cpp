// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; // 唯一一种需要clip的情况
        bool sign = (dividend^divisor) >= 0;
        unsigned int a = abs(dividend), b = abs(divisor), res = 0;
        while(a >= b){
            unsigned int cur = 1, base = b;
            while((a >> 1) > base){ // 这里要保证剩余的a要大于接下来的base(接下来base会翻倍)：a > 2*base，
                // base = cur*b，cur和base指数增长(cur = 1, 2, 4, 8, ...)
                cur <<= 1;
                base <<= 1;
            }
            res += cur;
            a -= base;
        }
        return sign ? res:-res;
    }
};