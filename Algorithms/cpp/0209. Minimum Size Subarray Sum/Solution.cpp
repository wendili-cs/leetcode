// https://leetcode-cn.com/problems/minimum-size-subarray-sum/
// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, prefix = 0, len = INT_MAX;
        while(r < n){
            prefix += nums[r];
            while(prefix >= target){
                len = min(len, r - l + 1);
                prefix -= nums[l];
                l++;
            }
            r++;
        }
        return len==INT_MAX?0:len;
    }
};