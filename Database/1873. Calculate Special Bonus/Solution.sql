-- https://leetcode-cn.com/problems/calculate-special-bonus/
SELECT employee_id, IF(employee_id%2=1, IF(substr(name, 1, 1)!="M", salary, 0), 0) as bonus
FROM Employees