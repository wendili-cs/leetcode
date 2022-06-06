// https://leetcode.com/problems/number-of-ways-to-split-array/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long> sums(nums.size(), 0);
        for(int i = 0; i < sums.size(); i++){
            sums[i] = nums[i] + (i==0?0:sums[i - 1]);
        }
        int res = 0;
        for(int i = 0; i < sums.size() - 1; i++){
            long left = sums[i];
            long right = sums.back() - left;
            if(left >= right) res++;
        }
        return res;
    }
};