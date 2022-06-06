// https://leetcode.com/problems/minimum-average-difference/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        long min_v = INT_MAX;
        int idx = -1;
        vector<long> sums(nums.size(), 0);
        for(int i = 0; i < sums.size(); i++){
            sums[i] = nums[i] + (i==0?0:sums[i - 1]);
        }
        for(int i = 0; i < sums.size(); i++){
            long left = sums[i]/(i + 1);
            long right = sums.back() - sums[i] == 0?0:(sums.back() - sums[i])/(sums.size() - i - 1);
            long ad = labs(left - right);
            if(min_v > ad){
                min_v = ad;
                idx = i;
            }
        }
        return idx;
    }
};