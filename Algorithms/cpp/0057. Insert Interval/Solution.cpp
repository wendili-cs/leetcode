// https://leetcode-cn.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return {};
        }
        else if(intervals.size()==1){
            return intervals;
        }

        vector<vector<int> > ans;
        sort(intervals.begin(), intervals.end());

        auto merge_interval = [](vector<int> &interval_a, vector<int> &interval_b) -> vector<int> {
            return {min(interval_a[0], interval_b[0]), max(interval_a[1], interval_b[1])};
        };

        auto merging_interval = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > merging_interval[1]){
                ans.push_back(merging_interval);
                merging_interval = intervals[i];
            }
            else{
                merging_interval = merge_interval(intervals[i], merging_interval);
            }
        }
        ans.push_back(merging_interval);
        return ans;
    }
};