// https://leetcode.com/problems/battleships-in-a-board/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0, m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        function<void(int, int)> dfs;
        dfs = [&](int x, int y) -> void {
            if(board[x][y] == '.' || board[x][y] == '-') return;
            board[x][y] = '-'; // 我们把X设置成-表示已经访问过这个地方
            for(auto &dir:dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n){
                    dfs(nx, ny);
                }
            }
            return;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    dfs(i, j);
                    res++;
                }
            }
        }
        return res;
    }
};