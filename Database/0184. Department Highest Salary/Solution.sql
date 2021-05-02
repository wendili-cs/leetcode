-- https://leetcode-cn.com/problems/department-highest-salary/

SELECT d.Name as Department, e.Name as Employee, e.Salary as Salary
FROM Employee e, Department d
WHERE e.DepartmentID = d.Id AND e.Salary = (SELECT MAX(Salary) FROM Employee e2 where e.DepartmentID = e2.DepartmentId)