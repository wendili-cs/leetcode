// https://leetcode.com/problems/shortest-path-to-get-food/

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ix = -1, iy = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '*'){
                    ix = i;
                    iy = j;
                    break;
                }
            }
            if(ix != -1) break;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(ix, iy));
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int steps = 0;
        while(!q.empty()){
            int q_size = q.size();
            steps++;
            for(int i = 0; i < q_size; i++){
                for(auto& dir:dirs){
                    int x = q.front().first + dir[0], y = q.front().second  + dir[1];
                    if(0 <= x && x < m && 0 <= y && y < n){
                        if(grid[x][y] == '#') return steps;
                        else if(grid[x][y] == 'O'){
                            q.push(make_pair(x, y));
                            grid[x][y] = 'X';
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};