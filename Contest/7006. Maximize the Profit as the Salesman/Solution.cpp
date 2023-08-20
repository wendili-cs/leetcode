// https://leetcode.com/contest/weekly-contest-359/problems/maximize-the-profit-as-the-salesman/

class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {
        if(a[1] == b[1]) return a[0] < a[0];
        return a[1] < b[1];
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int cur = 0, cmax = 0;
        sort(offers.begin(), offers.end(), cmp);
        vector<int> dp(n + 1, -100);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            while(cur < offers.size() && offers[cur][1] <= i){
                if(offers[cur][1] == i){
                    dp[i + 1] = max(dp[i + 1], dp[offers[cur][0]] + offers[cur][2]);
                    cmax = max(cmax, dp[i + 1]);
                }
                cur++;
            }
            dp[i + 1] = max(dp[i + 1], cmax);
        }
        return cmax;
    }
};