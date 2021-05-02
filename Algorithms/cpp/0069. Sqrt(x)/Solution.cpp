// https://leetcode-cn.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        if(x <= 1) return x;
        while(l + 1 < r){
            int m = (l + r)/2;
            if(m == x/m) return m;
            else if(m < x/m){
                l = m;
            }
            else{
                r = m;
            }
        }
        return l;
    }
};