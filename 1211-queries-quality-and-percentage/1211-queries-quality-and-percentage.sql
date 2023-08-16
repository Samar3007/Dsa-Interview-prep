# Write your MySQL query statement below
/* SELECT query_name, ROUND(avg(rating/position),2) AS quality,
ROUND(((rating<3) / count(query_name))*100,2) AS poor_query_percentage
FROM Queries group by query_name;
*/

SELECT query_name, ROUND(avg(rating/position),2) AS quality,
ROUND(AVG(rating<3)*100,2) AS poor_query_percentage
FROM Queries group by query_name;