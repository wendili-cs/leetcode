// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> dset(n);
        for(int i = 0; i < n; i++) dset[i] = i;
        function<int(int)> find;
        find = [&](int x) -> int {
            if(dset[x] != x) dset[x] = find(dset[x]);
            return dset[x];
        };
        for(auto& edge:edges){
            dset[find(edge[0])] = find(edge[1]);
        }
        set<int> s;
        for(int i = 0; i < n; i++) s.insert(find(i));
        return s.size();
    }
};