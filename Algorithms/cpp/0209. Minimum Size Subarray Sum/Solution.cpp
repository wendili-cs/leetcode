// https://leetcode-cn.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        if(len==0){
            return 0;
        }
        int res = INT_MAX, idx_1 = 0, idx_2 = 0 , sum = 0;
        while(idx_2 < len){
            sum += nums[idx_2];
            while(sum >= target){
                res = min(res, idx_2 - idx_1 + 1);
                sum -= nums[idx_1];
                idx_1++;
            }
            idx_2++;
        }
        return res==INT_MAX? 0:res;
    }
};