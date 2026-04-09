# Write your MySQL query statement below
select email from Person Group by email HAVING COUNT(email)>1;