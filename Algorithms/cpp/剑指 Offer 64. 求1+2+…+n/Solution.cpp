// https://leetcode-cn.com/problems/qiu-12n-lcof/

class Solution {
public:
    int sumNums(int n) {
        if(n <= 0) return 0;
        return n + sumNums(n - 1);
    }
};