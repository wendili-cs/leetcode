// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int M = 1000000007;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, -1)));
        vector<vector<int>> psum(m + 1, vector<int>(n + 1, 0));
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >=0; j--){
                psum[i][j] = psum[i + 1][j] + psum[i][j + 1] - psum[i + 1][j + 1];
                if(pizza[i][j] == 'A') psum[i][j]++;
            }
        }
        function<int(int, int, int)> dfs;
        dfs = [&](int x, int r, int c) -> int {
            if(psum[r][c] == 0) return 0;
            else if(x == 0) return 1;
            if(dp[x][r][c] == -1){
                int ret = 0;
                for(int hc = r + 1; hc < m; hc++){
                    if(psum[r][c] > psum[hc][c]){
                        ret += dfs(x - 1, hc, c);
                        ret = ret % M;
                    }
                }
                for(int vc = c + 1; vc < n; vc++){
                    if(psum[r][c] > psum[r][vc]){
                        ret += dfs(x - 1, r, vc);
                        ret = ret % M;
                    }
                }
                dp[x][r][c] = ret;
            }
            return dp[x][r][c];
        };

        return dfs(k - 1, 0, 0);
    }
};