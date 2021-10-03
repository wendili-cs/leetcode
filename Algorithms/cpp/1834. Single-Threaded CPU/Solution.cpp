// https://leetcode.com/problems/single-threaded-cpu/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        long t = INT_MAX;
        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i);
            t = min((long)tasks[i][0], t);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        int idx = 0;
        vector<int> res;
        while(idx < tasks.size() || !pq.empty()){
            while(idx < tasks.size() && tasks[idx][0] <= t){
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
            if(!pq.empty()){
                res.push_back(pq.top()[1]);
                t += pq.top()[0];
                pq.pop();
            }
            else{
                t = tasks[idx][0];
            }
        }
        return res;
    }
};