// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> pre; // prerequisites
        vector<int> req(numCourses, 0); // course i requires req[i] more courses
        for(auto& p:prerequisites){
            req[p[0]]++;
            pre[p[1]].insert(p[0]);
        }
        int scheduled = 0; // number of scheduled courses
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(req[i] == 0){
                q.push(i);
                scheduled++;
            }
        }
        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                int course = q.front();
                q.pop();
                // we remove this course from all the courses that require this course
                for(int pre_c:pre[course]){
                    req[pre_c]--;
                    if(req[pre_c] == 0){
                        q.push(pre_c);
                        scheduled++;
                    }
                }
            }
        }
        return scheduled == numCourses;
    }
};