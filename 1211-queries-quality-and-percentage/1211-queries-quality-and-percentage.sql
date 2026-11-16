# Write your MySQL query statement below
SELECT q.query_name,
ROUND(SUM(q.rating*1.0/q.position)/count(q.position),2) AS quality,
ROUND(SUM(CASE WHEN q.rating<3 THEN 1 ELSE 0 END)*100/count(q.position),2) AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name

