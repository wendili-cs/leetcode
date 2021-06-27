// https://leetcode-cn.com/problems/surrounded-regions/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        function<void(int, int)> recur;
        recur = [&](int x, int y) -> void {
            if(board[x][y] != 'O') return;
            board[x][y] = 'T';
            if(x > 0 && board[x - 1][y] == 'O') recur(x - 1, y);
            if(x < m - 1 && board[x + 1][y] == 'O') recur(x + 1, y);
            if(y > 0 && board[x][y - 1] == 'O') recur(x, y - 1);
            if(y < n - 1 && board[x][y + 1] == 'O') recur(x, y + 1);
        };
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') recur(i, 0);
            if(board[i][n - 1] == 'O') recur(i, n - 1);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') recur(0, j);
            if(board[m - 1][j] == 'O') recur(m - 1, j);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;
    }
};