// https://leetcode-cn.com/problems/sudoku-solver/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > row(9, vector<bool>(9, false)), col(9, vector<bool>(9, false)), block(9, vector<bool>(9, false));
        vector<vector<int> > spaces;
        bool is_valid = false;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') {
                    spaces.push_back({i, j});
                }
                else{
                    int num = board[i][j] - '1';
                    int block_idx = i/3*3 + j/3;
                    block[block_idx][num] = row[i][num] = col[j][num] = true;
                }
            }
        }
        function<void(int)> dfs;
        dfs = [&](int cnt) -> void {
            if(cnt == spaces.size()){
                is_valid = true;
                return;
            }
            int i = spaces[cnt][0], j = spaces[cnt][1], bidx = i/3*3 + j/3;
            for(int num = 0; num < 9 && !is_valid; num++){
                if(!block[bidx][num] && !row[i][num] && !col[j][num]){
                    block[bidx][num] = row[i][num] = col[j][num] = true;
                    board[i][j] = num + '1';
                    dfs(cnt + 1);
                    block[bidx][num] = row[i][num] = col[j][num] = false;
                }
            }
        };
        dfs(0);
    }
};