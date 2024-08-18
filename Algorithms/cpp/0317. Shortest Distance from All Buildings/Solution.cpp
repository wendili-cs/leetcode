// https://leetcode.com/problems/shortest-distance-from-all-buildings/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 1e4, num_builds = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) num_builds++;
            }
        }

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto find_dis = [&](int x, int y) -> int {
            // vector<vector<bool>> visited(m, vector<bool>(n, false));
            bool visited[50][50] = {false};
            visited[x][y] = true;
            queue<pair<int, int>> q;
            q.push(make_pair(x, y));
            int found = 0, total_dis = 0, cur_dis = 0;
            while(!q.empty()){
                cur_dis++;
                int qsize = q.size();
                for(int i = 0; i < qsize; i++){
                    auto pos = q.front();
                    q.pop();
                    for(auto& dir:dirs){
                        int nx = pos.first + dir[0], ny = pos.second + dir[1];
                        if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny]){
                            if(grid[nx][ny] == 1){
                                // find a new building
                                total_dis += cur_dis;
                                if(++found == num_builds) return total_dis;
                            }
                            else if(grid[nx][ny] == 0){
                                q.push({nx, ny});
                            }
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
            return 1e4;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    res = min(res, find_dis(i, j));
                }
            }
        }

        return res == 1e4 ? -1:res;
    }
};