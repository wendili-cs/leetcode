// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> g;
        for(auto &edge:edges){
            g[edge[0]].push_back(edge[1]);
        }
        function<void(int, vector<bool>&)> recur;
        recur = [&](int from, vector<bool>& visited) -> void {
            if(visited[from]) return;
            visited[from] = true;
            for(int i = 0; i < g[from].size(); i++){
                recur(g[from][i], visited);
            }
        };
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            vector<bool> vis(n, false);
            recur(i, vis);
            for(int j = 0; j < n; j++){
                if(vis[j] && i != j) res[j].push_back(i);
            }
        }
        return res;
    }
};