// https://leetcode.com/problems/a-number-after-a-double-reversal/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return !num?!num:num%10;
    }
};