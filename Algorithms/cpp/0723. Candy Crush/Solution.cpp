// https://leetcode.com/problems/candy-crush/

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool stable = true;
        int m = board.size(), n = board[0].size();
        // scan & find whether to crush
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i < m - 2 && board[i][j] != 0){
                    if(abs(board[i][j]) == abs(board[i + 1][j]) &&
                      abs(board[i][j]) == abs(board[i + 2][j])){
                        board[i][j] = board[i + 1][j] = board[i + 2][j] = -abs(board[i][j]);
                        stable = false;
                    }
                }
                if(j < n - 2 && board[i][j] != 0){
                    if(abs(board[i][j]) == abs(board[i][j + 1]) &&
                      abs(board[i][j]) == abs(board[i][j + 2])){
                        board[i][j] = board[i][j + 1] = board[i][j + 2] = -abs(board[i][j]);
                        stable = false;
                    }
                }
            }
        }
        if(stable) return board;
        // apply crush
        for(int j = 0; j < n; j++){
            for(int i = m - 1, cur = m - 1; i >= 0; i--, cur--){
                while(cur >= 0 && board[cur][j] < 0){
                    cur--;
                }
                board[i][j] = cur < 0? 0 : abs(board[cur][j]);
            }
        }
        return candyCrush(board);
    }
};