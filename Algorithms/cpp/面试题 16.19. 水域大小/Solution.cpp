// https://leetcode-cn.com/problems/pond-sizes-lcci/

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<int> sizes;
        vector<vector<bool> >visited(m, vector<bool>(n, false));
        function<int(int, int)> recur;
        recur = [&](int x, int y) -> int {
            if(x < 0 || x >= m || y < 0 || y >= n) return 0;
            if(visited[x][y] || land[x][y] != 0) return 0;
            visited[x][y] = true;
            int ret = 1;
            ret += recur(x - 1, y + 1);
            ret += recur(x - 1, y);
            ret += recur(x - 1, y - 1);
            ret += recur(x, y + 1);
            ret += recur(x, y - 1);
            ret += recur(x + 1, y + 1);
            ret += recur(x + 1, y);
            ret += recur(x + 1, y - 1);
            return ret;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j] == 0 && !visited[i][j]) sizes.push_back(recur(i, j));
            }
        }
        sort(sizes.begin(), sizes.end());
        return sizes;
    }
};