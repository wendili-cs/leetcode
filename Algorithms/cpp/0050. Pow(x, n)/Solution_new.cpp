// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0){
            x = 1.0/x;
            n = -(long)n;
        }
        // fast power
        function<double(double, long)> fast_pow;
        fast_pow = [&](double X, long N) -> double{
            if(N == 0){
                return 1.0;
            };
            double half = fast_pow(X, N/2);
            if(N&1){
                // mulitpy another X
                return half * half * X;
            }
            return half * half;
        };
        return fast_pow(x, n);
    }
};