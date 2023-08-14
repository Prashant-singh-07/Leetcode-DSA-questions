# Write your MySQL query statement below
select name as Employee from Employee as e where  e.managerId IN (select id from Employee as b where b.salary<e.salary);
