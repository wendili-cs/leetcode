// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mp; // mp[a] = {b, c} records that a is a prequisite of b and c
        vector<int> indegree(numCourses, 0), res;
        for(auto pre:prerequisites){
            mp[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                int node = q.front();
                q.pop();
                res.push_back(node);
                for(int next:mp[node]){
                    indegree[next]--;
                    if(indegree[next] == 0) q.push(next);
                }
            }
        }
        if(res.size()!=numCourses) res = {};
        return res;
    }
};