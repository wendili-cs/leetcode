https://leetcode-cn.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(),points.begin()+k,points.end(), [](auto&& l, auto&& r){return l[0]*l[0]+l[1]*l[1]<r[0]*r[0]+r[1]*r[1];});
        points.resize(k);
        return points;
    }
};