// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> grid(9);
        for(int i = 0; i < 9; i++){
            unordered_set<int> row, col;
            for(int j = 0; j < 9; j++){
                int gid = i/3*3 + j/3;
                if(board[i][j] != '.'){
                    if(row.find(board[i][j]) != row.end()) return false;
                    if(grid[gid].find(board[i][j]) != grid[gid].end()) return false;
                }
                if(board[j][i] != '.'){
                    if(col.find(board[j][i]) != col.end()) return false;
                }
                row.insert(board[i][j]);
                col.insert(board[j][i]);
                grid[gid].insert(board[i][j]);
            }
        }
        return true;
    }
};