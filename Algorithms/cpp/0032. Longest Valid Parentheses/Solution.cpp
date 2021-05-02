// https://leetcode-cn.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len < 2) return 0;
        vector<int> dp(len, 0); // 以dp[i]结尾的有效括号的长度
        for(int i = 1; i < len; i++){
            if(s[i] == ')'){
                int pre_idx = i - dp[i - 1] - 1; // 上一个未匹配元素的idx
                if(pre_idx >= 0 && s[pre_idx] == '('){
                    dp[i] = dp[i - 1] + 2;
                    if(pre_idx > 0) dp[i] += dp[pre_idx - 1]; // 消消乐合并pre_idx前面的
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};