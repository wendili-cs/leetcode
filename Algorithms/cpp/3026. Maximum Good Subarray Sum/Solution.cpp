// https://leetcode.com/problems/maximum-good-subarray-sum/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // mp[x] = y: value x has index
        int n = nums.size();
        vector<long> prefix_sum(n + 1, 0);
        for(int i = 0; i < n; i++) prefix_sum[i + 1] = prefix_sum[i] + nums[i];

        long res = -1e15;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i] - k) != mp.end()){
                res = max(res, prefix_sum[i + 1] - prefix_sum[mp[nums[i] - k]]);
            }
            if(mp.find(nums[i] + k) != mp.end()){
                res = max(res, prefix_sum[i + 1] - prefix_sum[mp[nums[i] + k]]);
            }
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = i; // no value-index recorded
            else if(mp.find(nums[i]) != mp.end() && prefix_sum[i] < prefix_sum[mp[nums[i]]]){
                mp[nums[i]] = i; // update this value-index mapping with the minimum prefix sum
            }
        }
        return res == -1e15 ? 0 : res;
    }
};