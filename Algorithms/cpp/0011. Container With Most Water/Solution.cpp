// https://leetcode-cn.com/problems/container-with-most-water/
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, res = 0;
        while(l < r){
            res = max(res, min(height[l], height[r])*(r - l));
            // move the pointer that points to the lower line
            if(height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
};