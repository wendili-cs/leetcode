// https://leetcode-cn.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_word_len = 0;
        for(const string& ws:wordDict) max_word_len = max(max_word_len, (int)ws.length());
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        int str_len = s.length();
        vector<bool> dp(str_len + 1, false);
        dp[0] = true;
        for(int i = 1; i <= str_len; i++){
            for(int j = max(0, i - max_word_len); j < i; j++){
                if(dp[j] && uset.find(s.substr(j, i - j)) != uset.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[str_len];
    }
};