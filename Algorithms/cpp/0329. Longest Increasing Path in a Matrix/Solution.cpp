// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<vector<int> > dp(m, vector<int>(n, -1));
        function<int(int, int)> recur;
        recur = [&](int x, int y) -> int {
            if(visited[x][y]) return 0;
            if(dp[x][y] != -1) return dp[x][y];
            visited[x][y] = true;
            int ret = 1;
            if(x > 0 && matrix[x - 1][y] > matrix[x][y]) ret = max(ret, 1 + recur(x - 1, y));
            if(x < m - 1 && matrix[x + 1][y] > matrix[x][y]) ret = max(ret, 1 + recur(x + 1, y));
            if(y > 0 && matrix[x][y - 1] > matrix[x][y]) ret = max(ret, 1 + recur(x, y - 1));
            if(y < n - 1 && matrix[x][y + 1] > matrix[x][y]) ret = max(ret, 1 + recur(x, y + 1));
            visited[x][y] = false;
            dp[x][y] = ret;
            return ret;
        };
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, recur(i, j));
            }
        }
        return res;
    }
};