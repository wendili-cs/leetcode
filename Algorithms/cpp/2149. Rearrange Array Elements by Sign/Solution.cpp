// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res;
        int p = 0, n = 0;
        while(nums[n] > 0) n++;
        while(nums[p] < 0) p++;
        while(n < nums.size() && p < nums.size()){
            res.push_back(nums[p]);
            p++;
            while(p < nums.size() && nums[p] < 0) p++;
            res.push_back(nums[n]);
            n++;
            while(n < nums.size() && nums[n] > 0) n++;
        }
        return res;
    }
};