# Write your MySQL query statement below
SELECT s.user_id, ROUND(AVG(CASE WHEN action = 'confirmed' THEN 1.00 ELSE 0.00 END),2) as confirmation_rate 
from Signups as s
LEFT JOIN Confirmations as c
on s.user_id=c.user_id
group by s.user_id