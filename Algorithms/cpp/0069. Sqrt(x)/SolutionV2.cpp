// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while(l < r){
            long mid = (l + r + 1)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x){
                if((mid + 1)*(mid + 1) > x) return mid;
                l = mid;
            }
            else if(mid*mid > x){
                r = mid;
            }
        }
        return l;
    }
};