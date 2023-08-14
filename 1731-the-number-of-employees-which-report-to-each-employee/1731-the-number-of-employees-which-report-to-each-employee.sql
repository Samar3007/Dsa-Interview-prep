# Write your MySQL query statement below
SELECT emp2.employee_id,emp2.name,count(emp1.reports_to) as reports_count,ROUND(avg(emp1.age)) as average_age FROM Employees as emp1
INNER JOIN Employees as emp2 
ON emp2.employee_id=emp1.reports_to
group by employee_id
order by employee_id