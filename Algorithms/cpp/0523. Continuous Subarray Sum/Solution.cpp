// https://leetcode-cn.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < len; i++){
            if(i > 0) nums[i] += nums[i - 1]; // 求和
            if((i > 0 && nums[i] % k == 0) || (m.find(nums[i]%k) != m.end() && m[nums[i]%k] <= i - 2)) return true;
            if(m.find(nums[i]%k) == m.end()) m[nums[i]%k] = i;
        }
        return false;
    }
};