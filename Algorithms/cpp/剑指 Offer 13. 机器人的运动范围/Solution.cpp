// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        function<int(int, int)> recur;
        recur = [&](int x, int y) -> int {
            int sum = x%10 + x/10 + y%10 + y/10;
            if(x < 0 || x >= m || y < 0 || y >= n || sum > k || visited[x][y]) return 0;
            visited[x][y] = true;
            return recur(x - 1, y) + recur(x + 1, y) + recur(x, y - 1) + recur(x, y + 1) + 1;
        };
        return recur(0, 0);
    }
};