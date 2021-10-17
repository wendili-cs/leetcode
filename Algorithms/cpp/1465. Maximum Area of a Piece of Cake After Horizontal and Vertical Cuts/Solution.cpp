// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int x = horizontalCuts[0], y = verticalCuts[0];
        horizontalCuts.push_back(h);
        for(int i = 1; i < horizontalCuts.size(); i++){
            x = max(x, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        verticalCuts.push_back(w);
        for(int i = 1; i < verticalCuts.size(); i++){
            y = max(y, verticalCuts[i] - verticalCuts[i - 1]);
        }
        long res = x;
        res = res*y%1000000007;
        return res;
    }
};