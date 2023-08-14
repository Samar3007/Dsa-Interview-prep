# Write your MySQL query statement below
SELECT emp2.name as Employee From Employee as emp1 
INNER JOIN Employee as emp2
ON emp1.id=emp2.managerId
where emp2.salary>emp1.salary