// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        // keep the sub in greedy
        // if a new element is larger than the largest element in sub, append it;
        // if a new element is not larger than that, replace the minimum larger element with this one
        for(int i = 0; i < nums.size(); i++){
            if(sub.empty() || sub.back() < nums[i]){
                sub.push_back(nums[i]);
            }
            else{
                // binary search
                auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
                *it = nums[i];
            }
        }
        return sub.size();
    }
};