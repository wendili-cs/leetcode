-- https://leetcode-cn.com/problems/products-price-for-each-store/

SELECT product_id,
SUM(IF(store='store1', price, null)) as store1,
SUM(IF(store='store2', price, null)) as store2,
SUM(IF(store='store3', price, null)) as store3
FROM Products
GROUP BY product_id