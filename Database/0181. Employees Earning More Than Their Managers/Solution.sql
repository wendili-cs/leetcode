-- https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/
SELECT e1.Name as Employee
FROM Employee e1, Employee e2
WHERE e1.ManagerId = e2.Id AND e1.Salary > e2.Salary 