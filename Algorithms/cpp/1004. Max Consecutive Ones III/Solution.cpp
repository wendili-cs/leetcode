// https://leetcode-cn.com/problems/max-consecutive-ones-iii/

// 思路：计算要填充成全1的累积值，然后accu这个数列是单调递增的，再使用二分查找。
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> accu(len + 1, 0);
        for(int i = 0; i < len; i++) accu[i + 1] = accu[i] + (1 - nums[i]);
        int res = 0;
        for(int r = 0; r < len; r++){
            int l = lower_bound(accu.begin(), accu.begin() + r + 1, accu[r + 1] - k) - accu.begin();
            res = max(res, r - l + 1);
        }
        return res;
    }
};