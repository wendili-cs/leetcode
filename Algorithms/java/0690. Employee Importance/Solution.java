// https://leetcode-cn.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    int res = 0;
    Map<Integer, Employee> map = new HashMap<>();
    public int getImportance(List<Employee> employees, int id) {
        for(var emp:employees) map.put(emp.id, emp);
        recur(id);
        return res;
    }

    public void recur(int id) {
        var emp = map.get(id);
        res += emp.importance;
        for(var sid:emp.subordinates) recur(sid);
    }
}