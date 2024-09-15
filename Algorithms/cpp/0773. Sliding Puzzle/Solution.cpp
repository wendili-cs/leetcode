// https://leetcode.com/problems/sliding-puzzle/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string state;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                state.push_back(board[i][j] + '0');
            }
        }
        vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}}; // adjacent's indices of each position
        queue<string> q;
        q.push(state);
        unordered_set<string> visited;
        visited.insert(state);
        int res = 0;
        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                string cur = q.front();
                if(cur == "123450") return res;
                q.pop();
                int idx = cur.find('0');
                for(int swap_idx:adj[idx]){
                    string new_str = cur;
                    swap(new_str[idx], new_str[swap_idx]);
                    if(visited.find(new_str) == visited.end()){
                        q.push(new_str);
                        visited.insert(new_str);
                    }
                }
            }
            res++;
        }
        return -1; // never arrive here
    }
};