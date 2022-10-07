// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> cols(9, 0), rows(9, 0), boxes(9, 0);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int bidx = (i/3)*3 + (j/3), cur = (1 << (board[i][j] - '0'));
                if(rows[i] & cur) return false;
                else rows[i] |= cur;
                if(cols[j] & cur) return false;
                else cols[j] |= cur;
                if(boxes[bidx] & cur) return false;
                else boxes[bidx] |= cur;
            }
        }
        return true;
    }
};