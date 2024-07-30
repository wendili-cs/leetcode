// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool neg = x < 0;
        if(neg) x = -x;
        int res = 0;
        while(x > 0){
            int num = x % 10;
            x /= 10;
            if(res > (INT_MAX - num)/10) return 0;
            res = 10*res + num;
        }
        return neg ? -res : res;
    }
};