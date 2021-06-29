-- https://leetcode-cn.com/problems/rising-temperature/
-- 要点：使用datediff求日期差

SELECT w1.id AS id FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.Temperature > w2.Temperature