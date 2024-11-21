// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res = m*n;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // 守卫和墙标记为1
        for(auto& g:guards) visited[g[0]][g[1]] = 1;
        for(auto& w:walls) visited[w[0]][w[1]] = 1;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto& g:guards){
            for(int i = 0; i < 4; i++){
                int nx = g[0] + dirs[i][0], ny = ny = g[1] + dirs[i][1];
                // 停止条件是直到碰到守卫或者墙
                while(0 <= nx && nx < m && 0 <= ny && ny < n && visited[nx][ny] != 1){
                    if(visited[nx][ny] == 0) res--;
                    visited[nx][ny] = 2;
                    nx += dirs[i][0];
                    ny += dirs[i][1];
                }
            }
        }
        res -= guards.size() + walls.size();
        return res;
    }
};