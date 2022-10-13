// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        deque<vector<int>> paths;
        vector<vector<int>> res;
        queue<int> q;
        q.push(0);
        paths.push_back({0});
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                int cur = q.front();
                q.pop();
                vector<int> tmp = paths.front();
                paths.pop_front();
                for(int j = 0; j < graph[cur].size(); j++){
                    int next = graph[cur][j];
                    if(next == n - 1){
                        tmp.push_back(n - 1);
                        res.push_back(tmp);
                        tmp.pop_back();
                    }
                    else{
                        q.push(next);
                        tmp.push_back(next);
                        paths.push_back(tmp);
                        tmp.pop_back();
                    }
                }
            }
        }
        return res;
    }
};