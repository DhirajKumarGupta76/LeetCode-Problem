# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE id % 2 = 1
  AND id 
  IN(SELECT id FROM Cinema WHERE description !='boring') 
ORDER BY rating DESC;