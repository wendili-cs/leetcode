// https://leetcode-cn.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > res = {};
        for(int idx_1 = 0; idx_1 < len; idx_1++){
            if(idx_1 > 0 && nums[idx_1] == nums[idx_1 - 1]){
                continue; // 忽略多个相等的值，只取最后的
            }
            int two_sum = -nums[idx_1], idx_3 = len - 1;
            for (int idx_2 = idx_1 + 1; idx_2 < len; idx_2++){
                if(idx_2 > idx_1 + 1 && nums[idx_2] == nums[idx_2 - 1]){
                    continue; // 忽略多个相等的值，只取最后的
                }
                while(nums[idx_2] + nums[idx_3] > two_sum && idx_2 < idx_3){
                    idx_3--;
                }
                if(idx_2 == idx_3){
                    break;
                }
                if(nums[idx_1] + nums[idx_2] + nums[idx_3] == 0){
                    res.push_back({nums[idx_1], nums[idx_2], nums[idx_3]});
                }
            }
        }
        return res;
    }
};
