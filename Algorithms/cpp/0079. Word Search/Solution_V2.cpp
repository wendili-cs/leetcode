// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), len = word.length();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<bool(int, int, int)> recur;
        recur = [&](int x, int y, int idx) -> bool {
            if(!visited[x][y] && board[x][y] == word[idx]){
                if(idx == len - 1) return true;
                visited[x][y] = true;
                for(auto &dir:dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n){
                        if(recur(nx, ny, idx + 1)) return true;
                    }
                }
                visited[x][y] = false;
            }
            return false;
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(recur(i, j, 0)) return true;
            }
        }
        return false;
    }
};