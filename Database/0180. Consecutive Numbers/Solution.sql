-- https://leetcode-cn.com/problems/consecutive-numbers/

SELECT DISTINCT L1.Num AS "ConsecutiveNums"
FROM Logs AS L1, Logs AS L2, Logs AS L3
WHERE L1.Num = L2.Num AND L1.Num = L3.Num AND L1.id = L2.id - 1 AND L1.id = L3.id - 2;