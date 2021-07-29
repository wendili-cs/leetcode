// https://leetcode-cn.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        set<pair<int, int> > s;
        for(int i = 0; i < points.size(); i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            s.insert(make_pair(dis, i));
        }
        vector<vector<int> > res;
        auto it = s.begin();
        for(int i = 0; i < k; i++){
            res.push_back(points[it->second]);
            it++;
        }
        return res;
    }
};