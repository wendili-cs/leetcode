// https://leetcode-cn.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size();
        function<void(int)> back_track;
        back_track = [&](int idx) -> void {
            if(idx == len){
                res.push_back(nums);
                return;
            }
            for(int i = idx; i < len; i++){
                swap(nums[i], nums[idx]); // 先交换
                back_track(idx + 1);
                swap(nums[i], nums[idx]); // 还原
                
            }
        };

        back_track(0);
        return res;
    }
};