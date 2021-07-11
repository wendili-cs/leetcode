// https://leetcode-cn.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> >res;
        vector<int> temp(k);
        function<void(int, int)> recur;
        recur = [&](int p, int remain) -> void {
            if(remain <= 0 || p >= k){
                if(remain == 0 && p == k) res.push_back(temp);
                return;
            }
            int origin = temp[p];
            for(int t = (p==0?1:temp[p-1]+1); t <= min(remain, 9); t++){
                temp[p] = t;
                recur(p + 1, remain - t);
            }
        };
        recur(0, n);
        return res;
    }
};