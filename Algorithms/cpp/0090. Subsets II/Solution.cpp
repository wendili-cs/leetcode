// https://leetcode-cn.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> temp_list;
        sort(nums.begin(), nums.end());

        function<void(bool, int)> dfs_p;
        dfs_p = [&](bool is_choosen, int idx){ // 第一个变量记录是否选择了上一个idx
            if(idx==nums.size()){
                res.push_back(temp_list);
                return;
            }
            dfs_p(true, idx + 1);
            if(is_choosen && idx > 0 && nums[idx-1]==nums[idx]){ // 前面的数字相同+选了上次的数字
                return;
            }
            temp_list.push_back(nums[idx]);
            dfs_p(false, idx + 1);
            temp_list.pop_back();
            
        };

        dfs_p(false, 0);
        return res;
    }
};