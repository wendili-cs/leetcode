// https://leetcode-cn.com/problems/subsets/
// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        function<void(int)> recur;
        recur = [&](int l) -> void {
            if(l >= nums.size()){
                res.push_back(temp);
                return;
            }
            recur(l + 1);
            temp.push_back(nums[l]);
            recur(l + 1);
            temp.pop_back();
        };
        recur(0);
        return res;
    }
};