// https://leetcode.com/problems/detonate-the-maximum-bombs/

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long dis = (long)(bombs[i][0] - bombs[j][0])*(bombs[i][0] - bombs[j][0]) + (long)(bombs[i][1] - bombs[j][1])*(bombs[i][1] - bombs[j][1]);
                long rr1 = (long)(bombs[i][2])*bombs[i][2];
                long rr2 = (long)(bombs[j][2])*bombs[j][2];
                if(dis <= rr1) g[i].push_back(j);
                if(dis <= rr2) g[j].push_back(i);
            }
        }
        
        auto bfs = [&](int idx) -> int {
            queue<int> q;
            q.push(idx);
            vector<bool> visited(n, false);
            int ret = 0;
            while(!q.empty()){
                int q_size = q.size();
                for(int i = 0; i < q_size; i++){
                    int cur = q.front();
                    q.pop();
                    if(!visited[cur]){
                        for(int& next:g[cur]){
                            if(!visited[next]) q.push(next);
                        }
                        ret++;
                    }
                    visited[cur] = true;
                }
            }
            return ret;
        };
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, bfs(i));
        }
        return res;
    }
};