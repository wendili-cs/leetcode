// https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/

class Solution {
public:
    int houseOfCards(int n) {
        int res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n/3 + 2, -1));
        function<int(int, int)> recur;
        recur = [&](int remain, int last_num) -> int {
            // cout << remain << " " << last_num << endl;
            if(remain <= 0) return remain==0 ? 1:0;
            if(dp[remain][last_num] == -1) {
                int ret = 0;
                for(int i = 0; 3*i + 2 <= remain && i < last_num; i++){
                    ret += recur(remain - 3*i - 2, i);
                }
                dp[remain][last_num] = ret;
            }
            return dp[remain][last_num];
        };
        
        return recur(n, n/3 + 1);
    }
};