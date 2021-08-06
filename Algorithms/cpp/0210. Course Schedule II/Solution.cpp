// https://leetcode-cn.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int> > adjacent;
        vector<int> indegree(numCourses), res;
        for(auto prereq:prerequisites){
            adjacent[prereq[1]].insert(prereq[0]);
            indegree[prereq[0]]++;
        }
        deque<int> proc;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) proc.push_back(i);
        }
        while(!proc.empty()){
            for(int course_id:adjacent[proc.front()]){
                if(--indegree[course_id] == 0) proc.push_back(course_id);
            }
            res.push_back(proc.front());
            proc.pop_front();
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] != 0) return {};
        }
        return res;
    }
};