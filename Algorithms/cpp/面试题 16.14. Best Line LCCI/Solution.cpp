// https://leetcode-cn.com/problems/best-line-lcci/

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        int len = points.size();
        vector<int> res(2, -1);
        int max_cnt = 0;
        unordered_map<double, vector<int> > umap;
        // sort(points.begin(), points.end());
        for(int i = 0; i < len; i++){
            umap.clear();
            for(int j = i + 1; j < len; j++){
                double d_y = points[i][1] - points[j][1], d_x = points[i][0] - points[j][0];
                double k = d_x==0? DBL_MAX:d_y/d_x;
                umap[k].push_back(j);
            }
            for(auto iter:umap){
                if(iter.second.size() > max_cnt || (iter.second.size() == max_cnt && res[0] == i && iter.second[0] < res[1])){
                    res[0] = i;
                    res[1] = iter.second[0];
                    max_cnt = iter.second.size();
                }
            }
        }
        return res;
    }
};