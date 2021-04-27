// https://leetcode-cn.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        function<void(int, int)> recurr;
        int m = grid.size(), n = grid[0].size();
        recurr = [&](int x, int y) -> void {
            if(grid[x][y] == '0' || grid[x][y] == '2'){
                return;
            }
            grid[x][y] = '2';
            if(x > 0) recurr(x - 1, y);
            if(x < m - 1) recurr(x + 1, y);
            if(y > 0) recurr(x, y - 1);
            if(y < n - 1) recurr(x, y + 1);
            return;
        };
        int sum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    recurr(i, j);
                    sum += 1;
                }
            }
        }

        return sum;
    }
};