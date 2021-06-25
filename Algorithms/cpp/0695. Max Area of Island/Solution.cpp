// https://leetcode-cn.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        function<int(int, int)> recur;
        recur = [&](int x, int y) -> int {
            if(grid[x][y] == 0) return 0;
            int ret = 1;
            grid[x][y] = 0;
            if(x > 0 && grid[x - 1][y] == 1) ret += recur(x - 1, y);
            if(x < m - 1 && grid[x + 1][y] == 1) ret += recur(x + 1, y);
            if(y > 0 && grid[x][y - 1] == 1) ret += recur(x, y - 1);
            if(y < n - 1 && grid[x][y + 1] == 1) ret += recur(x, y + 1);
            return ret;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    res = max(res, recur(i, j));
            }
        }
        return res;
    }
};