// https://leetcode.com/problems/flower-planting-with-no-adjacent/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int m = 4; // number of colors
        vector<unordered_set<int>> adjs(n);
        for(auto& p:paths){
            adjs[p[0] - 1].insert(p[1] - 1);
            adjs[p[1] - 1].insert(p[0] - 1);
        }
        vector<int> coloring(n, -1); // value should be from [1, m - 1]
        auto bfs = [&](int p) -> void {
            queue<int> q;
            q.push(p);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                if(coloring[cur] != -1) continue; // cur has been colored
                vector<bool> temp(m + 1, false); // used color
                for(int adj:adjs[cur]){
                    if(coloring[adj] != -1){
                        temp[coloring[adj]] = true; // this color is used
                    }
                    else{
                        q.push(adj);
                    }
                }
                for(int c = 1; c <= m; c++){
                    if(temp[c] == false){
                        coloring[cur] = c;
                        break;
                    }
                }
            }
        };
        
        for(int i = 0; i < n; i++){
            if(coloring[i] == -1){
                bfs(i);
            }
        }
        return coloring;
    }
};