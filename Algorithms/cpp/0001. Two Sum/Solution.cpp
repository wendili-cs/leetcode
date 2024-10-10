// https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> Q2A;
        for(int i = 0; i < nums.size(); i++){
            auto iter = Q2A.find(target - nums[i]);
            if(iter != Q2A.end()){
                return {iter->second, i};
            }
            Q2A.emplace(nums[i], i);
        }
        return {-1, -1}; // 反正不可能到达此位置
    }
};