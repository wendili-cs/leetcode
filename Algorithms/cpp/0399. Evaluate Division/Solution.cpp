// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        for(int i = 0; i < equations.size(); i++){
            mp[equations[i][0]][equations[i][1]] = values[i];
            mp[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        unordered_set<string> visited;
        function<double(string, string)> dfs;
        dfs = [&](string a, string b) -> double {
            if(mp.find(a) == mp.end()) return -1.0;
            if(a == b) return 1.0;
            if(mp[a].find(b) != mp[a].end()) return mp[a][b]; // if we have the transition
            visited.insert(a);
            for(auto it:mp[a]){ // otherwise, fine other possible ways for transition
                if(visited.find(it.first) != visited.end()) continue;
                double rate = dfs(it.first, b);
                if(rate > 0.0){
                    visited.erase(a);
                    return it.second*rate;
                }
            }
            visited.erase(a);
            return -1.0;
        };
        vector<double> res;
        for(auto &q:queries){
            res.push_back(dfs(q[0], q[1]));
        }
        return res;
    }
};