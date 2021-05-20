// https://leetcode-cn.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> Q(n, -1);
        auto is_valid = [&](int cur_x, int cur_y) -> bool {
            for(int i = 0; i < cur_x; i++){
                if(Q[i] == cur_y || Q[i] - i == cur_y - cur_x || Q[i] + i == cur_y + cur_x) return false;
            }
            return true;
        };

        function<void(int)> recur;
        recur = [&](int x) -> void { //第一个参数记录现在是哪一行，第二个参数记录在哪一列
            if(x == n){
                string row = string(n, '.');
                vector<string> board;
                for(int i = 0; i < n; i++){
                    board.push_back(row);
                    board[i][Q[i]] = 'Q';
                }
                res.push_back(board);
            }
            for(int i = 0; i < n; i++){
                if(!is_valid(x, i))
                    continue;
                Q[x] = i;
                recur(x + 1);
            }
        };
        recur(0);
        return res;
    }
};