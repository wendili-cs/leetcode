### 示例：找第二高的薪水
1. 有可能存在相同薪水的情况，注意去重distinct
2. 给查询的结果起别名 用as，语法：原列名 as 新列名
3. 分类order by，默认升序排列（ASC），降序排列（DESC）
4. 限制结果数量LIMIT，只有一个参数时，代表行数；2个参数时，LIMIT(偏移量，显示行数)，偏移量从0开始计数；返回第二条记录，用 Limit 1,1
```
select distinct Salary as SecondHighestSalary from Employee order by Salary DESC Limit 1,1;
```