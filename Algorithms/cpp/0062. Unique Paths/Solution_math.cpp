https://leetcode-cn.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int sum = m + n - 2;
        for(int i = 1; i <= min(n - 1, m - 1); i++){
            res *= sum;
            res /= i;
            sum--;
        }
        return res;
    }
};