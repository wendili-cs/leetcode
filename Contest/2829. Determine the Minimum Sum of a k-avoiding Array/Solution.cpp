// https://leetcode.com/contest/weekly-contest-359/problems/determine-the-minimum-sum-of-a-k-avoiding-array/

class Solution {
public:
    int minimumSum(int n, int k) {
        int num_dec = (k - 1)/2;
        if(2*n - 1 < k) return (1 + n)*n/2;
        int tmp = (1 + num_dec + n)*(num_dec + n)/2;
        int tmp2 = (k/2 + k/2 + num_dec + 1)*num_dec/2;
        return tmp - tmp2;
    }
};