// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> g;
        for(int i = 0; i < n - 1; i++){
            g[i].insert(i + 1);
        }
        auto bfs = [&]() -> int {
            queue<int> q;
            for(int x:g[0]) q.push(x);
            int ret = 1;
            unordered_set<int> visited;
            while(!q.empty()){
                int qsize = q.size();
                for(int i = 0; i < qsize; i++){
                    int x = q.front();
                    q.pop();
                    if(x == n - 1) return ret;
                    for(int next:g[x]){
                        if(visited.find(next) == visited.end()){
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
                ret++;
            }
            return ret;
        };
        vector<int> res;
        for(auto& q:queries){
            g[q[0]].insert(q[1]);
            res.push_back(bfs());
        }
        return res;
    }
};