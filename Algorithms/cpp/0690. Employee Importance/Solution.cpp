// https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> id2e;
        for(auto e:employees){
            id2e[e->id] = e;
        }
        function<int(int)> recur;
        recur = [&](int eid){
            int ret = id2e[eid]->importance;
            for(auto sid:id2e[eid]->subordinates){
                ret += recur(sid);
            }
            return ret;
        };
        return recur(id);
    }
};