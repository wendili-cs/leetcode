// https://leetcode-cn.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp_list;
        vector<vector<int> > res;
        function<void(int)> dfs;
        dfs = [&](int idx) -> void {
            if(idx == nums.size()){
                res.push_back(temp_list);
                return;
            }
            dfs(idx + 1);
            temp_list.push_back(nums[idx]);
            dfs(idx + 1);
            temp_list.pop_back();
        };
        
        dfs(0);
        return res;
    }
};