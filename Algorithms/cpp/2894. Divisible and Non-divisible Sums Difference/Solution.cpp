// https://leetcode.com/contest/weekly-contest-366/problems/divisible-and-non-divisible-sums-difference/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (1 + n)*n/2 - (m + n - (n%m))*(n/m);
    }
};