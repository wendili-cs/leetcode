// https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips-ii/

class Solution {
public:
    int removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        vector<vector<int>> ones;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) ones.push_back({i, j});
            }
        }
        queue<vector<vector<int>>> q;
        if(ones.empty()) return 0;
        q.push(ones);
        while(!q.empty()){
            int q_size = q.size();
            cnt++;
            for(int i = 0; i < q_size; i++){
                vector<vector<int>> o = q.front();
                q.pop();
                for(int j = 0; j < o.size(); j++){
                    vector<vector<int>> next;
                    int x = o[j][0], y = o[j][1];
                    for(auto it:o){
                        if(it[0] != x && it[1] != y){
                            next.push_back(it);
                        }
                    }
                    if(next.empty()) return cnt;
                    q.push(next);
                }
            }
        }
        return cnt;
    }
};