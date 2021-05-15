// https://leetcode-cn.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > used(m, vector<bool>(n, false));
        function<bool(int, int, string)> recurr;
        recurr = [&](int x, int y, string s) -> bool {
            if(s.empty()) return true;
            if(used[x][y] || board[x][y] != s[0]) return false;
            used[x][y] = true;
            bool res = false;
            if(x > 0 && recurr(x - 1, y, s.substr(1))) return true;
            if(x < m - 1 && recurr(x + 1, y, s.substr(1))) return true;
            if(y > 0 && recurr(x, y - 1, s.substr(1))) return true;
            if(y < n - 1 && recurr(x, y + 1, s.substr(1))) return true;
            used[x][y] = false;
            return s.substr(1).empty();
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(recurr(i, j, word)) return true;
            }
        }
        return false;
    }
};