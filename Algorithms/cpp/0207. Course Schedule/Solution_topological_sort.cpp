// https://leetcode-cn.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int> > adjcent; // 记录每个课的prereq有哪些
        vector<int> indegree(numCourses, 0); // 记录每个课的入度
        for(auto prereq:prerequisites){
            adjcent[prereq[1]].insert(prereq[0]);
            indegree[prereq[0]]++;
        }
        deque<int> proc; // 每次要删除的内容
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) proc.push_back(i);
        }
        while(!proc.empty()){
            for(int course_id:adjcent[proc.front()]){
                if(--indegree[course_id] == 0) proc.push_back(course_id);
            }
            proc.pop_front();
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};