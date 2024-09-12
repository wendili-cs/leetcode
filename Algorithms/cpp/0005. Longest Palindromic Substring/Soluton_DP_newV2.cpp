// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<bool(int, int)> recur;
        recur = [&](int l, int r) -> bool {
            if(l == r) return true;
            if(l == r - 1) return s[l] == s[r];
            if(dp[l][r] == -1){
                if(s[l] == s[r] && recur(l + 1, r - 1)){
                    dp[l][r] = 1;
                }
                else{
                    dp[l][r] = 0;
                }
            }
            return dp[l][r];
        };
        int max_len = 0, max_idx = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(j - i + 1 > max_len && recur(i, j)){
                    max_len = j - i + 1;
                    max_idx = i;
                }
            }
        }
        return s.substr(max_idx, max_len);
    }
};