// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), max_len = 1;
        pair<int, int> lr = {0, 0};
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for(int i = 0; i < n; i++) dp[i][i] = true;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(len == 2) dp[i][j] = s[i] == s[j];
                else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                if(dp[i][j] && max_len < len){
                    max_len = len;
                    lr = make_pair(i, j);
                }
            }
        }
        return s.substr(lr.first, lr.second - lr.first + 1);
    }
};