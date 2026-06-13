// https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/description/

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int start = max(1, n - k), res = 0;
        for(int x = start; x <= n + k; x++){
            if((x & n) == 0) {
                res += x;
            }
        }
        return res;
    }
};