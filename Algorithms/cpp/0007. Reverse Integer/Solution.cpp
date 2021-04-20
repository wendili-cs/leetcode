// https://leetcode-cn.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        long long int n = 0;
        while(x){
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n > INT_MAX || n < INT_MIN? 0 : (int)n;
    }
};