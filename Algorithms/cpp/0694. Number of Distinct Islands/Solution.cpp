// https://leetcode.com/problems/number-of-distinct-islands/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<void(int, int, char)> dfs;
        set<string> s;
        string cur_island;
        dfs = [&](int x, int y, char d) -> void {
            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1 || visited[x][y]) return;
            cur_island.push_back(d);
            visited[x][y] = true;
            vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            vector<char> cs = {'r', 'd', 'l', 'u'};
            for(int i = 0; i < 4; i++){
                dfs(x + dirs[i][0], y + dirs[i][1], cs[i]);
            }
            cur_island.push_back('0'); // necessary for some similar graphs
        };
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    cur_island.clear();
                    dfs(i, j, '1');
                    s.insert(cur_island);
                }
            }
        }
        return s.size();
    }
};