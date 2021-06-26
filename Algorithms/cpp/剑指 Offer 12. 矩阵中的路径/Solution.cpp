// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        function<bool(int, int, string, vector<vector<bool> >&)> recur;
        recur = [&](int x, int y, string cur, vector<vector<bool> >& is_visited) -> bool {
            if(cur.empty()) return true;
            if(is_visited[x][y]) return false;
            is_visited[x][y] = true;
            if(cur[0] == board[x][y]){
                if(cur.length() == 1) return true;
                if(x > 0 && cur[1] == board[x - 1][y] && recur(x - 1, y, cur.substr(1), is_visited)) return true;
                if(x < m - 1 && cur[1] == board[x + 1][y] && recur(x + 1, y, cur.substr(1), is_visited)) return true;
                if(y > 0 && cur[1] == board[x][y - 1] && recur(x, y - 1, cur.substr(1), is_visited)) return true;
                if(y < n - 1 && cur[1] == board[x][y + 1] && recur(x, y + 1, cur.substr(1), is_visited)) return true;
            }
            is_visited[x][y] = false;
            return false;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j] && recur(i, j, word, visited)) return true;
            }
        }
        return false;
    }
};