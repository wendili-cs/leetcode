// https://leetcode.com/contest/weekly-contest-370/problems/maximum-score-after-applying-operations-on-a-tree/

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> mp, ump;
        for(int i = 0; i < edges.size(); i++){
            ump[edges[i][0]].push_back(edges[i][1]);
            ump[edges[i][1]].push_back(edges[i][0]);
        }
        
        // from undirected mapping (ump) to directed mapping (mp)
        unordered_set<int> s;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            s.insert(q.front());
            int q_size = ump[q.front()].size();
            for(int i = 0; i < q_size; i++){
                int to = ump[q.front()][i];
                if(s.find(to) == s.end()){
                    mp[q.front()].push_back(to);
                    q.push(to);
                }
            }
            q.pop();
        }
        
        vector<int> mem(n, -1);
        function<long(int)> dfs;
        dfs = [&](int x) -> long{ // determine the minimal sums that can be left
            if(mem[x] == -1){
                if(mp[x].size() == 0) mem[x] = values[x];
                else{
                    long tmp = 0;
                    for(int sub:mp[x]){
                        tmp += dfs(sub);
                    }
                    mem[x] = (tmp > values[x] ? values[x] : tmp);
                }
            }
            return mem[x];
        };
        long res = 0;
        for(int v:values) res += v;
        return res - dfs(0);
    }
};