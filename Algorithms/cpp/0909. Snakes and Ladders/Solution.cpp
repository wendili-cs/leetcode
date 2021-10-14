// https://leetcode.com/problems/snakes-and-ladders/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), res = 1;
        auto get_val = [&](int pos) -> int {
            pos--;
            int row = pos/n;
            int col = (row&1)?n-1-pos%n:pos%n;
            return board[n - 1 - row][col];
        };
        queue<int> q;
        set<int> s;
        q.push(board[0][0]==-1?1:board[0][0]);
        while(!q.empty()){
            int q_size = q.size();
            for(int j = 0; j < q_size; j++){
                int cur = q.front();
                q.pop();
                for(int i = 1; i <= 6; i++){
                    int temp = get_val(cur + i);
                    int next = temp==-1?cur + i:temp;
                    if(s.find(next) != s.end()) continue;
                    if(next == n*n) return res;
                    int transfer = get_val(next);
                    q.push(next);
                    s.insert(next);
                }
            }
            res++;
        }
        return -1;
    }
};