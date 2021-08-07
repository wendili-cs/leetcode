// https://leetcode-cn.com/problems/course-schedule-iv/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        map<int, vector<int> > adjacent;
        vector<int> indegree(numCourses);
        for(auto prereq:prerequisites){
            adjacent[prereq[0]].push_back(prereq[1]);
            indegree[prereq[1]]++;
        }
        deque<int> proc;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) proc.push_back(i);
        }
        map<int, set<int> > find;
        while(!proc.empty()){
            for(int course_id:adjacent[proc.front()]){
                if(--indegree[course_id] == 0) proc.push_back(course_id);
                find[course_id].insert(proc.front());
                for(int it:find[proc.front()]) find[course_id].insert(it);
            }
            proc.pop_front();
        }
        // 开始查询
        vector<bool> res;
        for(auto query:queries){
            if(find[query[1]].find(query[0]) != find[query[1]].end()) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};