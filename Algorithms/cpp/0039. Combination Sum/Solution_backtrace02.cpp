// https://leetcode-cn.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        function<void(int, int, vector<int>&)> recur;
        recur = [&](int idx, int tmp_sum, vector<int> &tmp) -> void {
            if(idx >= len || tmp_sum >= target){
                if(tmp_sum == target && !tmp.empty()) res.push_back(tmp);
                return;
            }
            vector<int> tmp_new = vector<int>(tmp);
            tmp_new.push_back(candidates[idx]);
            recur(idx, tmp_sum + candidates[idx], tmp_new);
            recur(idx + 1, tmp_sum, tmp);
            return;
        };
        vector<int> temp;
        recur(0, 0, temp);
        return res;
    }
};