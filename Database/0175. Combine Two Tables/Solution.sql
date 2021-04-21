-- https://leetcode-cn.com/problems/combine-two-tables/
-- Write your MySQL query statement below
SELECT p.FirstName, p.LastName, a.City, a.State
FROM Person p LEFT OUTER JOIN Address a
ON p.PersonId = a.PersonId