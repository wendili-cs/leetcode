// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k > nums.size()){
            if(nums.size() == 1) return (k&1) ? -1:nums[0];
            return *max_element(nums.begin(), nums.end());
        }
        else if(k == 0) return nums[0];
        else if(k == 1) return nums.size() > 1 ? nums[1]:-1;
        // 2 <= k <= n - 1
        return max(*max_element(nums.begin(), nums.begin() + k - 1), nums[k]);
    }
};