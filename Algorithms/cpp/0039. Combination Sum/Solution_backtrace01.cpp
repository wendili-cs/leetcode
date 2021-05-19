// https://leetcode-cn.com/problems/combination-sum/

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：10.6 MB, 在所有 C++ 提交中击败了73.62%的用户

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;

        vector<int> temp;
        function<void(int, int)> recur;
        recur = [&](int start, int remain) -> void {
            if(remain == 0) res.push_back(temp);
            for(int i = start; i < len && remain >= candidates[i]; i++){
                temp.push_back(candidates[i]);
                recur(i, remain - candidates[i]);
                temp.pop_back();
            }
            return;
        };
        recur(0, target);
        return res;
    }
};