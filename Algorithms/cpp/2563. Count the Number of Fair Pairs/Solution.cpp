// https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int start = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int end = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            res += end - start;
        }
        return res;
    }
};