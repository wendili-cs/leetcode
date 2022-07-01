// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        set<vector<int>> s;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<vector<int>> q;
        visited[start[0]][start[1]] = true;
        q.push(start);
        int dis = 0;
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                if(pricing[0] <= grid[x][y] && grid[x][y] <= pricing[1]) 
                    s.insert({dis, grid[x][y], x, y});
                for(auto& dir:dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny] && grid[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            dis++;
        }
        vector<vector<int>> res;
        auto it = s.begin();
        for(int i = 0; i < k; i++){
            if(it != s.end()){
                res.push_back({(*it)[2], (*it)[3]});
                it++;
            }
        }
        return res;
    }
};