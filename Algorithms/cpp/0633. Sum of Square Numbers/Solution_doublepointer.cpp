// https://leetcode-cn.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = (int)sqrt(c), t;
        while(l <= r){
            t = l*l + r*r;
            if(t == c) return true;
            else if(t < c) l++;
            else if(t > c) r--;
        }
        return false;
    }
};