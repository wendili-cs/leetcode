// https://leetcode-cn.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> cbj(n);
        for(int i = 0; i < n; i++) cbj[i] = i;
        function<int(int)> find;
        find = [&](int x) -> int {
            if(cbj[x] != x) cbj[x] = find(cbj[x]);
            return cbj[x];
        };
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j] == 1) cbj[find(j)] = find(i);
            }
        }
        set<int> s;
        for(int i = 0; i < n; i++) s.insert(find(i));
        return s.size();
    }
};