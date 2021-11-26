// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        height.push_back(0);
        height.insert(height.begin(), 0);
        int l = 0, r = height.size() - 1, res = 0, l_max = 0, r_max = 0;
        while(l < r){
            if(l_max < r_max){
                res += max(0, l_max - height[l]);
                l++;
                l_max = max(l_max, height[l]);
            }
            else{
                res += max(0, r_max - height[r]);
                r--;
                r_max = max(r_max, height[r]);
            }
        }
        return res;
    }
};