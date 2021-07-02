// https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges/

// 思路：动态规划，其中对于每个未记录在案的，考虑让其[减到可以除以2]、[减到可以除以3]这两种情况哪个更优，并存储下来
class Solution {
public:
    int minDays(int n) {
        map<int, int> dp;
        function<int(int)> recur;
        recur = [&](int t) -> int {
            if(t <= 1) return t;
            if(dp.find(t) == dp.end()) 
                dp[t] = min(recur(t/2) + t%2 + 1, recur(t/3) + t%3 + 1);
            return dp[t];
        };
        return recur(n);
    }
};