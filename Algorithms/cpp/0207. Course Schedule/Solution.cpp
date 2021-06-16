// https://leetcode-cn.com/problems/course-schedule/

// 关键：找有向图中是否存在闭环
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > g;
        for(auto& pre:prerequisites) g[pre[0]].push_back(pre[1]);
        vector<int> visited(numCourses, 0);

        function<bool(int)> dfs;
        dfs = [&](int v) -> bool { // 2表示访问结束，1表示正在访问，0表示未访问
            if(visited[v] == 2) return false;
            else if(visited[v] == 1) return true;
            visited[v] = 2;
            for(int next_v:g[v]){
                if(!dfs(next_v)) return false;
            }
            visited[v] = 1;
            return true;
        };

        bool res = true;
        for(int i = 0; i < numCourses; i++){
            res &= dfs(i);
        }
        return res;
    }
};