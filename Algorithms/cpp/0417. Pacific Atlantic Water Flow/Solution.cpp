// https://leetcode-cn.com/problems/pacific-atlantic-water-flow/

// 要点：反向算流向两个洋的水流经的位置（visited），计算交集
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool> > visited_pa(m, vector<bool>(n, false)), visited_at(m, vector<bool>(n, false));
        function<void(vector<vector<bool> >&, int, int)> dfs;
        dfs = [&](vector<vector<bool> >& visited, int x, int y) -> void {
            visited[x][y] = true;
            if(x > 0 && heights[x - 1][y] >= heights[x][y]){
                if(!visited[x - 1][y]) dfs(visited, x - 1, y);
            }
            if(x < m - 1 && heights[x + 1][y] >= heights[x][y]){
                if(!visited[x + 1][y]) dfs(visited, x + 1, y);
            }
            if(y > 0 && heights[x][y - 1] >= heights[x][y]){
                if(!visited[x][y - 1]) dfs(visited, x, y - 1);
            }
            if(y < n - 1 && heights[x][y + 1] >= heights[x][y]){
                if(!visited[x][y + 1]) dfs(visited, x, y + 1);
            }
        };
        for(int i = 0; i < m; i++){
            dfs(visited_pa, i, 0);
            dfs(visited_at, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            dfs(visited_pa, 0, j);
            dfs(visited_at, m - 1, j);
        }
        vector<vector<int> > res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited_at[i][j] && visited_pa[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};