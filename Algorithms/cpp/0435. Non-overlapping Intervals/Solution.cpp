// https://leetcode-cn.com/problems/non-overlapping-intervals/

// 重点思想：贪心，按照internal的结尾来排
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1]==b[1]? a[0] < b[0]:a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        int pidx = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] >= intervals[pidx][1]){
                cnt++;
                pidx = i;
            }
        }
        return intervals.size() - cnt;
    }
};