// https://leetcode-cn.com/problems/meeting-rooms-ii/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int t = intervals[0][0], res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < intervals.size(); i++){
            t = intervals[i][0];
            pq.push(intervals[i][1]);
            while(pq.top() <= t) pq.pop();
            res = max(res, (int)pq.size());
        }
        return res;
    }
};