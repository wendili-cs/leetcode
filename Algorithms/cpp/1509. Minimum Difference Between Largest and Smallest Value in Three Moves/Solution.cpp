// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3) return 0;
        sort(nums.begin(), nums.end());
        int min_val = INT_MAX, len = nums.size();
        for(int i = 0; i <= 3; i++){
            min_val = min(abs(nums[i] - nums[len-(3-i)-1]), min_val);
        }
        return min_val;
    }
};