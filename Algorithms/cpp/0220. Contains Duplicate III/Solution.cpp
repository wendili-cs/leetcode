// https://leetcode-cn.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> uset;
        for(int i = 0; i < nums.size(); i++){
            long temp = nums[i];
            auto iter = uset.lower_bound(temp - t);
            if(iter != uset.end() && *iter <= temp + t) return true;
            uset.insert(nums[i]);
            if(i >= k) uset.erase(nums[i - k]);
        }
        return false;
    }
};