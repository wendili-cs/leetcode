// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> board(m, vector<int>(n, 0));
        for(auto& g:guards){
            board[g[0]][g[1]] = 1; // 1 for block
        }
        for(auto& w:walls){
            board[w[0]][w[1]] = 1;
        }
        
        auto guard_at = [&](int x, int y) -> void {
            int nx = x - 1, ny = y;
            while(0 <= nx && nx < m && 0 <= ny && ny < n){
                if(board[nx][ny] == 0) board[nx][ny] = 2; // 2 for guarded
                else if(board[nx][ny] == 1) break;
                nx--;
            }
            nx = x + 1, ny = y;
            while(0 <= nx && nx < m && 0 <= ny && ny < n){
                if(board[nx][ny] == 0) board[nx][ny] = 2; // 2 for guarded
                else if(board[nx][ny] == 1) break;
                nx++;
            }
            nx = x, ny = y - 1;
            while(0 <= nx && nx < m && 0 <= ny && ny < n){
                if(board[nx][ny] == 0) board[nx][ny] = 2; // 2 for guarded
                else if(board[nx][ny] == 1) break;
                ny--;
            }
            nx = x, ny = y + 1;
            while(0 <= nx && nx < m && 0 <= ny && ny < n){
                if(board[nx][ny] == 0) board[nx][ny] = 2; // 2 for guarded
                else if(board[nx][ny] == 1) break;
                ny++;
            }
        };
        
        for(auto& g:guards){
            guard_at(g[0], g[1]);
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0) res++;
            }
        }
        return res;
    }
};