// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0), tar = sum - x;
        int l = 0, r = 0, cur = 0, res = INT_MAX;
        while(r < nums.size()){
            cur += nums[r];
            r++;
            while(l < r && cur > tar){
                cur -= nums[l];
                l++;
            }
            if(cur == tar){
                res = min(res, (int)nums.size() - (r - l));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};