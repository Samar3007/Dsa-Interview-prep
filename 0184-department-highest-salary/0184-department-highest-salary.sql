# Write your MySQL query statement below
SELECT dep.name as Department, emp.name as Employee, emp.salary From Employee as emp 
inner join Department as dep 
ON emp.departmentId=dep.id and  
emp.salary=(select max(salary) from Employee as e2 where e2.departmentId=dep.id);