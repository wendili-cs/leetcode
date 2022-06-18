-- https://leetcode.com/problems/the-number-of-users-that-are-eligible-for-discount/

CREATE FUNCTION getUserIDs(startDate DATE, endDate DATE, minAmount INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT COUNT(DISTINCT user_id) FROM Purchases
      WHERE time_stamp BETWEEN startDate AND endDate
      AND amount >= minAmount
  );
END