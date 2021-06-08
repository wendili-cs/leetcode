// https://leetcode-cn.com/problems/palindrome-partitioning-ii/

class Solution {
public:
    int minCut(string s) {
        if(s.length() <= 1) return 0;
        vector<int> dp(s.length());
        for(int i = 0; i < s.length(); i++) dp[i] = i;
        auto calc_pali_len = [&](int i, int j) {
            while(j < s.length() && i >= 0 && s[i] == s[j]){
                dp[j] = min(dp[j], i==0? 0:dp[i - 1] + 1);
                i--;
                j++;
            }
        };
        for(int m = 0; m < s.length(); m++){
            calc_pali_len(m, m);
            calc_pali_len(m, m + 1);
        }
        return dp.back();
    }
};