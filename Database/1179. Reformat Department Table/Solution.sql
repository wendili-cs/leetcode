-- https://leetcode-cn.com/problems/reformat-department-table/
-- 要点：通过id来group by，然后用if语句选择性相加

SELECT 
id,
sum(IF(month="Jan", revenue, null)) as Jan_Revenue,
sum(IF(month="Feb", revenue, null)) as Feb_Revenue,
sum(IF(month="Mar", revenue, null)) as Mar_Revenue,
sum(IF(month="Apr", revenue, null)) as Apr_Revenue,
sum(IF(month="May", revenue, null)) as May_Revenue,
sum(IF(month="Jun", revenue, null)) as Jun_Revenue,
sum(IF(month="Jul", revenue, null)) as Jul_Revenue,
sum(IF(month="Aug", revenue, null)) as Aug_Revenue,
sum(IF(month="Sep", revenue, null)) as Sep_Revenue,
sum(IF(month="Oct", revenue, null)) as Oct_Revenue,
sum(IF(month="Nov", revenue, null)) as Nov_Revenue,
sum(IF(month="Dec", revenue, null)) as Dec_Revenue
FROM Department GROUP BY Department.id;