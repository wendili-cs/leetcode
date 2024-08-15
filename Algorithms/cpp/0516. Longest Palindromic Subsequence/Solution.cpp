// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> recur;
        recur = [&](int l, int r) -> int {
            if(l > r) return 0;
            if(l == r) return 1;
            if(dp[l][r] != -1) return dp[l][r];
            if(s[l] == s[r]){
                dp[l][r] = 2 + recur(l + 1, r - 1);
            }
            else{
                dp[l][r] = max(recur(l + 1, r), recur(l, r - 1));
            }
            return dp[l][r];
        };
        return recur(0, n - 1);
    }
};