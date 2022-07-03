// https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n, -1);
        function<long(int)> recur;
        recur = [&](int idx) -> long {
            if(idx >= n) return 0;
            if(dp[idx] == -1){
                long skip = recur(idx + 1);
                long solve = recur(idx + questions[idx][1] + 1) + questions[idx][0];
                dp[idx] = skip > solve ? skip:solve;
            }
            return dp[idx];
        };
        return recur(0);
    }
};