// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 1) return s != "0";
        int n = s.length(), res = 0;
        auto check_valid = [&](int i) -> bool {
            if(i == 0 || s[i - 1] > '2' || s[i - 1] == '0') return false;
            int t = stoi(s.substr(i - 1, 2));
            return t <= 26;
        };
        
        // dp[i + 1] = dp[i - 1] + dp[i] + (whether s[i - 1] + s[i] is valid); 0 if not valid and s[i] == 0
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = (s[0] != '0');
        for(int i = 2; i <= n; i++){
            if(!check_valid(i - 1)){
                dp[i] = (s[i - 1] == '0'? 0:dp[i - 1]);
            }
            else{
                dp[i] = (s[i - 1] == '0'? 0:dp[i - 1]) + dp[i - 2];
            }
        }
        return dp.back();
    }
};