// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, lmax = height[l], rmax = height[r], res = 0;
        while(l < r){
            if(lmax > rmax){
                r--;
                rmax = max(rmax, height[r]);
                res += rmax - height[r];
            }
            else{
                l++;
                lmax = max(lmax, height[l]);
                res += lmax - height[l];
            }
        }
        return res;
    }
};