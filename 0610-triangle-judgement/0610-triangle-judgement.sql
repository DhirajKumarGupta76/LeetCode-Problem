# Write your MySQL query statement below

SELECT *, 
CASE WHEN X+Y>Z && X+Z>Y && Y+Z>X THEN "Yes" 
ELSE "No" END AS triangle
FROM Triangle 
