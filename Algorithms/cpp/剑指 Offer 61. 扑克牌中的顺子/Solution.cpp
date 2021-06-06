// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        while(nums[idx] == 0) idx++;
        for(int i = idx; i < 4; i++){
            if(nums[i] == nums[i + 1]) return false;
        }
        return nums.back() - nums[idx] <= 4;
    }
};