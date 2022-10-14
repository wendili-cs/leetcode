// https://leetcode-cn.com/problems/merge-intervals/
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto merge_intervals = [](vector<int> &a, vector<int> &b) -> vector<int> {
            return {min(a[0], b[0]), max(a[1], b[1])};
        };
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto &interval:intervals){
            if(!res.empty() && res.back()[1] >= interval[0]){
                vector<int> new_interval = merge_intervals(res.back(), interval);
                res.back() = new_interval;
            }
            else{
                res.push_back(interval);
            }
        }
        return res;
    }
};