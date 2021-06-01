// https://leetcode-cn.com/problems/decode-ways/

// f(n) = f(n - 1) + f(n - 2)，其中s[n] == 0的情况下f(n)取0，10 <= int(s[n-2:n]) <= 26的情况下f(n-2)不取0
class Solution {
public:
    int numDecodings(string s) {
        int count = 0;
        if(s.length() == 0 || s[0] == '0') return 0;
        else if(s.length() == 1) return 1;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.length(); i++){
            dp[i + 1] = s[i] == '0'? 0:dp[i];
            if(i > 0){
                int temp = stoi(s.substr(i - 1, 2));
                dp[i + 1] += (10 <= temp && temp <= 26)? dp[i - 1]:0;
            }
        }
        return dp.back();
    }
};