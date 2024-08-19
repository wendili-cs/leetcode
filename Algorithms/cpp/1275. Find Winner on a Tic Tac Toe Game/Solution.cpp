// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        map<int, int> row, col, cross;
        int isA = 1;
        for(auto& move:moves){
            row[move[0]] += isA;
            col[move[1]] += isA;
            // cross[0] means x == y, cross[1] means x + y == 2 case
            if(move[0] == move[1]) cross[0] += isA;
            if(move[0] + move[1] == 2) cross[1] += isA;
            if(abs(row[move[0]]) == 3 || abs(col[move[1]]) == 3 ||
            abs(cross[0]) == 3 || abs(cross[1]) == 3) return isA > 0 ? "A":"B";
            isA *= -1;
        }
        return moves.size() == 9 ? "Draw":"Pending";
    }
};