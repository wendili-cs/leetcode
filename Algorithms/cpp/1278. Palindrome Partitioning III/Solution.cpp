// https://leetcode-cn.com/problems/palindrome-partitioning-iii/
// 要点：动态规划
//      f[i][j]表示从前个char切i段回文最少要修改几个字符
//      状态转移方程：f[i][j] = min([f[i-1][t-1] + cost[t][j])
//      其中cost[t][j]是s[i:j+1]这段要变成回文至少修改多少个char

class Solution {
public:
    int palindromePartition(string s, int k) {
        int len = s.length();
        vector<vector<int> > cost(len, vector<int>(len, 0)); // 从i到j之内要变成回文要更改多少次char
        for(int lr = 2; lr <= len; lr++){
            for(int i = 0; i < len && i + lr - 1 < len; i++){
                int j = i + lr - 1;
                if(lr == 2) cost[i][j] = s[i]==s[j]?0:1;
                else cost[i][j] = cost[i + 1][j - 1] + (s[i]==s[j]?0:1);
            }
        }
        const int max_v = 101;
        vector<vector<int> > dp(k + 1, vector<int>(len, max_v));
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < len; j++){
                // dp[i][j] = dp[i - 1][0] + cost[j][len - 1];
                for(int t = i - 1; t < len; t++){
                    dp[i][j] = min(dp[i][j], (t>0?dp[i - 1][t - 1]:0) + cost[t][j]);
                }
            }
        }
        return dp.back().back();
    }
};