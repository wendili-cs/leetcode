// https://leetcode-cn.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // 前面的n是总共n个9个数，后面是一个1-9的bin count
        vector<vector<bool> > row(n, vector(n, false)), col(n, vector(n, false)), squ(n, vector(n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int block_n = i/3*(n/3) + j/3;
                    if(squ[block_n][num]||row[i][num]||col[j][num]) return false;
                    squ[block_n][num] = true;
                    row[i][num] = true;
                    col[j][num] = true;
                }
            }
        }
        return true;
    }
};