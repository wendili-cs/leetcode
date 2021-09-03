// https://leetcode-cn.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int> >q;
        int m = grid.size(), n = grid[0].size(), cnt = 0; // cnt是新鲜橘子数
        auto get_adj = [&](int x, int y) -> vector<vector<int> > {
            vector<vector<int> > ret;
            vector<vector<int> > actions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for(auto& action:actions){
                int n_x = x + action[0], n_y = y + action[1];
                if(0 <= n_x && n_x < m && 0 <= n_y && n_y < n){
                    if(grid[n_x][n_y] == 1) ret.push_back({n_x, n_y});
                }
            }
            return ret;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    cnt++;
                    // if(get_adj(i, j).empty()) return -1;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int res = 0;
        while(!q.empty() && cnt != 0){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                vector<vector<int> > adjs = get_adj(q.front()[0], q.front()[1]);
                for(int j = 0; j < adjs.size(); j++){
                    grid[adjs[j][0]][adjs[j][1]] = 2;
                    cnt--;
                    q.push(adjs[j]);
                }
                q.pop();
            }
            res++;
        }
        return cnt==0?res:-1;
    }
};