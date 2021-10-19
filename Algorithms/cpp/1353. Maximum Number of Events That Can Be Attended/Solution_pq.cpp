// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int i = 0, len = events.size(),  res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int d = 1; d <= 100000 && (!pq.empty()||i < len); d++){
            while(!pq.empty() && pq.top() < d) pq.pop();
            while(i < len && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty() && pq.top() >= d){
                res++;
                pq.pop();
            }
        }
        return res;
    }
};