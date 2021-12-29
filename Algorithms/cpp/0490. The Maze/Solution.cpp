// https://leetcode.com/problems/the-maze/

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push(start);
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                vector<int> p = q.front();
                q.pop();
                if(p == destination) return true;
                vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(auto dir:dirs){
                    int nx = p[0], ny = p[1];
                    while(0 <= nx + dir[0] && nx + dir[0] < m && 0 <= ny + dir[1] && ny + dir[1] < n && maze[nx + dir[0]][ny + dir[1]] != 1){
                        nx += dir[0];
                        ny += dir[1];
                    }
                    if(!visited[nx][ny]){
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return false;
    }
};