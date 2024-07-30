// https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(), res = INT_MIN;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // element format {difference, x, y}
        pq.push({0, 0, 0});
        visited[0][0] = true;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()){
            vector<int> ele = pq.top();
            pq.pop();
            int x = ele[1], y = ele[2];
            visited[x][y] = true;
            res = max(ele[0], res);
            if(x == m - 1 && y == n - 1) return res;
            for(auto dir:dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny]){
                    pq.push({abs(heights[x][y] - heights[nx][ny]), nx, ny});
                }
            }
        }
        return res;
    }
};