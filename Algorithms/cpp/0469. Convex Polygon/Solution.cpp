// https://leetcode.com/problems/convex-polygon/
// idea refer to: https://leetcode.com/problems/convex-polygon/solutions/95578/python-o-n-by-checking-the-directions-of-every-edge-learned-from-robert-sedgewick-s-algorithm-course

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        auto calc_cross_product = [&](int x) -> int {
            // 0 <= x < points.size()
            vector<int> a = (x == 0) ? points.back() : points[x - 1]; // previous point
            vector<int> b = points[x]; // current point
            vector<int> c = (x == points.size() - 1) ? points[0] : points[x + 1]; // next point (in a cycle)
            // cross product: (b - a)x(c - a) should be always > 0 or always < 0 (if = 0, skip)
            return (b[0] - a[0])*(c[1] - a[1]) - (b[1] - a[1])*(c[0] - a[0]);
        };
        int greater_than_0 = 0, product; // -1 for false, 1 for true, 0 for undefined
        for(int i = 0; i < points.size(); i++){
            product = calc_cross_product(i);
            if(product == 0) continue;
            if(greater_than_0 == 0) greater_than_0 = product > 0 ? 1 : -1;
            if(greater_than_0*product < 0) 
                return false; // products are not all >=0 NOR not all <= 0
        }
        return true;
    }
};