// https://leetcode-cn.com/problems/design-tic-tac-toe/

class TicTacToe {
private:
    int l, diag1 = 0, diag2 = 0;
    vector<int> brow, bcol;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n){
        l = n;
        brow = vector<int>(n);
        bcol = vector<int>(n);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        brow[col] += (player==1?1:-1);
        bcol[row] += (player==1?1:-1);
        if(col == row) diag1 += (player==1?1:-1);
        if(col + row == l - 1) diag2 += (player==1?1:-1);
        if(brow[col] == l || bcol[row] == l || diag1 == l || diag2 == l) return 1;
        else if(brow[col] == -l || bcol[row] == -l || diag1 == -l || diag2 == -l) return 2;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */