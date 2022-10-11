// https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2, res = 0;
        sort(costs.begin(), costs.end(), cmp);
        for(int i = 0; i < costs.size(); i++){
            res += (i < n) ? costs[i][0] : costs[i][1];
        }
        return res;
    }
};