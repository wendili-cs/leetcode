// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        auto calc_slope = [&](int i, int j) -> double {
            int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
            int dx = x1 - x2, dy = y1 - y2;
            if(dy == 0) return (double)100000.0;
            return dx/(double)dy;
        };
        int n = points.size(), res = 1;
        for(int i = 0; i < n; i++){
            // from slope -> number of points
            unordered_map<double, int> mp;
            int cur_max = 0;
            for(int j = i + 1; j < n; j++){
                double slope = calc_slope(i, j);
                cur_max = max(cur_max, ++mp[slope] + 1);
            }
            res = max(cur_max, res);
        }
        return res;
    }
};