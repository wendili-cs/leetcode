// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        auto cnt_nei = [&](int x, int y) -> int {
            int res = 0;
            vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
            for(auto& dir:dirs){
                int nx = x + dir[0], ny = y + dir[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n && abs(board[nx][ny])==1){
                    res++;
                }
            }
            return res;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int nei_num = cnt_nei(i, j);
                if(nei_num < 2 || nei_num > 3) board[i][j] = -board[i][j];
                else if(nei_num == 3 && board[i][j] == 0) board[i][j] = 2;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] < 0) board[i][j] = 0;
            }
        }
    }
};