# Write your MySQL query statement below

-- Exactly! You understood it correctly. ✅
-- - Numerator: COUNT(DISTINCT player_id) → Counts unique players from the filtered rows (after applying WHERE).
-- - Denominator: (SELECT COUNT(DISTINCT player_id) FROM Activity) → Counts unique players from the original Activity table (all rows, without the outer WHERE filter).


SELECT
ROUND(COUNT(DISTINCT player_id) * 1.0 /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction
FROM Activity
# get minium date of interval 1 day for each player_id
WHERE (player_id, event_date) 
IN (
    SELECT player_id,DATE_ADD(MIN(event_date), INTERVAL 1 DAY)
    FROM Activity
    GROUP BY player_id
    );
