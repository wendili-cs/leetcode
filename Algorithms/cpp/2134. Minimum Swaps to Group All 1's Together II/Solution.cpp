// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), cur = nums[0];
        int l = 0, r = 0, min_swap = INT_MAX;
        while(l < nums.size()){
            while(r - l + 1 < sum){
                r++;
                cur += nums[r%nums.size()];
            }
            min_swap = min(min_swap, sum - cur);
            cur -= nums[l];
            l++;
        }
        return min_swap;
    }
};