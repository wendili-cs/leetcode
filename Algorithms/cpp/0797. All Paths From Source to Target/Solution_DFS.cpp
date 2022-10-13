// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> tmp;
        vector<vector<int>> res;
        function<void(int)> dfs;
        dfs = [&](int idx) -> void{
            tmp.push_back(idx);
            if(idx == n - 1){
                res.push_back(tmp);
            }
            for(int i = 0; i < graph[idx].size(); i++){
                dfs(graph[idx][i]);
            }
            tmp.pop_back();
        };
        dfs(0);
        return res;
    }
};