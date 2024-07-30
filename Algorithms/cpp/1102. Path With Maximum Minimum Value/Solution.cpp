// https://leetcode.com/problems/path-with-maximum-minimum-value/

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int res = INT_MAX;
        priority_queue<vector<int>> pq;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // structure in pq: {value of this point, x, y}
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()){
            vector<int> pos = pq.top();
            pq.pop();
            res = min(res, pos[0]);
            if(pos[1] == m - 1 && pos[2] == n - 1) return res;
            for(auto dir:dirs){
                int nx = pos[1] + dir[0], ny = pos[2] + dir[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny]){
                    pq.push({grid[nx][ny], nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return res;
    }
};