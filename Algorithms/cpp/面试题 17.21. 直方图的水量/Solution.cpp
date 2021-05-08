// https://leetcode-cn.com/problems/volume-of-histogram-lcci/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, max_left = 0, max_right = 0, res = 0;
        while(left <= right){
            if(max_left < max_right){
                res += max(0, max_left - height[left]);
                max_left = max(max_left, height[left]);
                left++;
            }
            else{
                res += max(0, max_right - height[right]);
                max_right = max(max_right, height[right]);
                right--;
            }
        }
        return res;
    }
};