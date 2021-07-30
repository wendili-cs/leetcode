// https://leetcode-cn.com/problems/max-consecutive-ones-ii/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l, r, sum = 0, res = 0;
        for(l = 0, r = 0; r < nums.size(); r++){
            sum += nums[r];
            res = max(res, r - l);
            while(r - l + 1 > sum + 1){ // 这里不能是while
                sum -= nums[l];
                l++;
            }
        }
        return max(res, r - l);
    }
};