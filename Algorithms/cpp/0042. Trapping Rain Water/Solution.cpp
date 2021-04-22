// https://leetcode-cn.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int l_max = 0, r_max = 0;
        int res = 0;
        while(left <= right){
            if(r_max >= l_max){
                res += max(0, l_max - height[left]);
                l_max = max(height[left], l_max);
                left++;
            }
            else{
                res += max(0, r_max - height[right]);
                r_max = max(height[right], r_max);
                right--;
            }
        }
        return res;
    }
};