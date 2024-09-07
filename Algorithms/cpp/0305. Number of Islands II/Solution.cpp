// https://leetcode.com/problems/number-of-islands-ii/

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> dset(m*n);
        for(int i = 0; i < m*n; i++) dset[i] = i;
        function<int(int)> find;
        find = [&](int x) -> int {
            if(dset[x] != x) dset[x] = find(dset[x]);
            return dset[x];
        };

        set<pair<int, int>> s;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int cur = 0; // curent islands
        vector<int> res;
        for(auto& p:positions){
            int x = p[0], y = p[1];
            if(s.find(make_pair(x, y)) == s.end()){ // avoid duplicate points
                cur++; // add new one
                for(auto& dir:dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n){
                        if(s.find(make_pair(nx, ny)) != s.end()){
                            int tmp1 = x*n + y, tmp2 = nx*n + ny;
                            if(find(tmp1) != find(tmp2)) cur--; // if we our current one is adjacent to other island, counter--
                            dset[find(tmp1)] = find(dset[tmp2]); // update to present them as together
                        }
                    }
                }
                s.insert(make_pair(x, y));
            }
            res.push_back(cur);
        }
        return res;
    }
};