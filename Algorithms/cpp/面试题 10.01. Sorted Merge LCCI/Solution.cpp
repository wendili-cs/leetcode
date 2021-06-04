// https://leetcode-cn.com/problems/sorted-merge-lcci/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int mn = m + n;
        while(mn > 0){
            if(m != 0 && (n == 0 || A[m - 1] > B[n - 1])) A[--mn] = A[--m];
            else A[--mn] = B[--n];
        }
    }
};