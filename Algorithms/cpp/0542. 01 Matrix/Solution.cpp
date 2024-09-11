// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto &dir:dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && res[nx][ny] == -1){
                        res[nx][ny] = res[x][y] + 1;
                        q.emplace(nx, ny);
                    }
                }
            }   
        }
        return res;
    }
};