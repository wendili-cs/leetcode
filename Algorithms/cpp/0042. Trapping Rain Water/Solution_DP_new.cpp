// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        vector<int> dpl(n, 0), dpr(n, 0); // 从左往右、从右往左的最高高度
        for(int i = 1; i < n; i++){
            dpl[i] = max(height[i - 1], dpl[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--){
            dpr[i] = max(height[i + 1], dpr[i + 1]);
        }
        for(int i = 0; i < n; i++){
            res += max(0, min(dpl[i], dpr[i]) - height[i]);
        }
        return res;
    }
};