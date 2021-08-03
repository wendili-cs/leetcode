// https://leetcode-cn.com/problems/meeting-rooms-ii/

class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b) {return a[0]==b[0]?a[1] < b[1]: a[0] < b[0];}
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto interval:intervals){
            if(!pq.empty() && pq.top() <= interval[0]){
                pq.pop();
            }
            pq.emplace(interval[1]);
            res = max(res, (int)pq.size());
        }
        return res;
    }
};