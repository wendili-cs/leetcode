// https://leetcode.com/problems/minimum-area-rectangle/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, map<int, bool> > m;
        int res = INT_MAX;
        for(auto& point:points) m[point[0]][point[1]] = true;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                    // 两个矩形中相对的点
                    if(m[points[i][0]][points[j][1]] && m[points[j][0]][points[i][1]]){
                        // 存在组成矩形的点
                        res = min(res, abs((points[i][0]-points[j][0])*(points[i][1]-points[j][1])));
                    }
                }
            }
        }
        return res==INT_MAX?0:res;
    }
};