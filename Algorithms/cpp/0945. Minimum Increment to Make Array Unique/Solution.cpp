// https://leetcode.com/problems/minimum-increment-to-make-array-unique/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = nums[0], add = 0;
        for(int i = 0; i < nums.size(); i++){
            add += max(0, cur - nums[i]);
            cur = max(nums[i] + 1, cur + 1);
        }
        return add;
    }
};