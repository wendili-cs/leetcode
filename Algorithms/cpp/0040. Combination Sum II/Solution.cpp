// https://leetcode-cn.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int len = candidates.size();
        vector<vector<int> > res;
        vector<int> temp;
        function<void(int, int)> recur;
        recur = [&](int idx, int remain) -> void {
            if(remain <= 0){
                if(remain == 0) res.push_back(temp);
                return;
            }
            for(int i = idx; i < len; i++){
                if(i > idx && candidates[i] == candidates[i - 1]) continue;
                temp.push_back(candidates[i]);
                recur(i + 1, remain - candidates[i]);
                temp.pop_back();
            }
        };
        recur(0, target);
        return res;
    }
};