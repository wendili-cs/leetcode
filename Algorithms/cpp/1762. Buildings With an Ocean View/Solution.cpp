// https://leetcode.com/problems/buildings-with-an-ocean-view/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        res.push_back(heights.size() - 1);
        int cur = heights.back();
        for(int i = heights.size() - 1; i > 0; i--){
            if(heights[i - 1] > cur){
                res.push_back(i - 1);
                cur = heights[i - 1];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};