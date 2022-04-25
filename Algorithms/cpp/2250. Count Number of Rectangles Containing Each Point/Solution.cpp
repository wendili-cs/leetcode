// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> hs(101); // split rectangles according to their heights
        for(auto &rec:rectangles){
            hs[rec[1]].push_back(rec[0]);
        }
        for(int i = 0; i < 101; i++){
            sort(hs[i].begin(), hs[i].end());
        }
        vector<int> res;
        for(auto &p:points){
            int cnt = 0;
            for(int i = p[1]; i < 101; i++){
                auto it = lower_bound(hs[i].begin(), hs[i].end(), p[0]);
                cnt += hs[i].end() - it;
            }
            res.push_back(cnt);
        }
        return res;
    }
};