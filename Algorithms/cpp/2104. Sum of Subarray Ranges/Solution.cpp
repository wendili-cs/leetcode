// https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long res = 0;
        for(int i = 0; i < nums.size(); i++){
            long vmin = nums[i], vmax = nums[i];
            for(int j = i; j < nums.size(); j++){
                vmin = vmin > nums[j] ? nums[j]:vmin;
                vmax = vmax < nums[j] ? nums[j]:vmax;
                res += vmax - vmin;
            }
        }
        return res;
    }
};