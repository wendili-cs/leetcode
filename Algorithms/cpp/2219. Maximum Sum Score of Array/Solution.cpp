// https://leetcode.com/problems/maximum-sum-score-of-array/

class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        vector<long> sums(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            sums[i + 1] = nums[i] + sums[i];
        }
        long res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            res = (res >= sums[i + 1])?res:sums[i + 1];
            res = (res >= sums.back()-sums[i])?res:sums.back()-sums[i];
        }
        return res;
    }
};