// https://leetcode.com/problems/minesweeper/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        auto cnt_mines = [&](vector<int> pos) {
            int ret = 0;
            for(auto& dir:dirs){
                int nx = pos[0] + dir[0], ny = pos[1] + dir[1];
                if(0 <= nx && nx < m && 0 <= ny && ny < n){
                    ret += board[nx][ny] == 'M';
                }
            }
            return ret;
        };
        
        function<void(vector<int>)> recur;
        recur = [&](vector<int> pos) -> void {
            if(board[pos[0]][pos[1]] != 'M'){
                int num_mines = cnt_mines(pos);
                if(num_mines == 0){
                    board[pos[0]][pos[1]] = 'B';
                    for(auto& dir:dirs){
                        int nx = pos[0] + dir[0], ny = pos[1] + dir[1];
                        if(0 <= nx && nx < m && 0 <= ny && ny < n && board[nx][ny] == 'E'){
                            recur({nx, ny});
                        }
                    }
                }
                else{
                    board[pos[0]][pos[1]] = num_mines + '0';
                }
            }
        };
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        recur(click);
        return board;
    }
};