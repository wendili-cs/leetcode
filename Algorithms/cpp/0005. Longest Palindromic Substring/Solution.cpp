// https://leetcode-cn.com/problems/longest-palindromic-substring/submissions/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1){
            return s;
        }
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for(int i = 0; i < len; i++){
            dp[i][i] = true;
        }
        int longest = 0, start_idx;
        for(int L = 1; L <= len; L++){ // 字符串的长度是L
            for(int i = 0; i < len; i++){ // 左边的index
                int j = L + i - 1; // 右边的index
                if(j >= len){
                    break;
                }
                if(s[i]==s[j]){
                    if(L <= 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                else{
                    dp[i][j] = false;
                }

                if(dp[i][j] && L > longest){
                    longest = L;
                    start_idx = i;
                }
            }
        }

        return s.substr(start_idx, longest);
    }
};