# Write your MySQL query statement below
select MAX(num)as num from (select num from MyNumbers Group By num Having Count(num) = 1)AS single_numbers;