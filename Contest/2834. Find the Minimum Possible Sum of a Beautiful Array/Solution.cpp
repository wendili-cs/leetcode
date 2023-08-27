https://leetcode.com/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        if(target > 2*n + 1) return (long)n*(n + 1)/2;
        long missed = (target - 1)/2;
        // t = 3 -> 2
        // t = 4 -> 3
        // t = 5 -> 3,4
        // t = 6 -> 4,5
        // t = 7 -> 4,5,6
        long sum = (1 + (n+missed))*(n+missed)/2;
        long begin = target/2 + 1;
        long tmp = (begin + begin + missed - 1)*missed/2;
        return sum - tmp;
    }
};