// https://leetcode.com/problems/connecting-cities-with-minimum-cost/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
    int find(vector<int> &bcj, int x) {
        if(bcj[x] != x) bcj[x] = find(bcj, bcj[x]);
        return bcj[x];
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> bcj(n);
        for(int i = 0; i < n; i++) bcj[i] = i;
        
        sort(connections.begin(), connections.end(), cmp);
        
        int res = 0;
        for(auto& connect:connections){
            if(find(bcj, connect[0] - 1) != find(bcj, connect[1] - 1)){
                res += connect[2];
                bcj[find(bcj, connect[0] - 1)] = find(bcj, connect[1] - 1);
            }
        }
        set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(find(bcj, bcj[i]));
        }
        return s.size()==1?res:-1;
    }
};