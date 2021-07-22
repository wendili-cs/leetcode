// https://leetcode-cn.com/problems/last-stone-weight-ii/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<set<int> > sums(2);
        sums[0].insert(0);
        int idx = 0;
        function<void(int)> recur;
        recur = [&](int pos) -> void {
            if(pos >= stones.size()) return;
            sums[1 - idx].clear();
            for(auto it = sums[idx].begin(); it != sums[idx].end(); it++){
                sums[1 - idx].insert(*it + stones[pos]);
                sums[1 - idx].insert(*it - stones[pos]);
            }
            idx = 1 - idx;
            recur(++pos);
        };
        recur(0);
        int res = INT_MAX;
        for(auto it = sums[idx].begin(); it != sums[idx].end(); it++){
            res = min(res, abs(*it));
        }
        return res;
    }
};