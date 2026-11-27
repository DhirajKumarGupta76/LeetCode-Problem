# Write your MySQL query statement below

-- Get the latest price of each product before or on 2019-08-16
SELECT product_id, new_price AS price
FROM Products
WHERE (product_id, change_date) IN
(
    -- Find the latest change date for each product
    SELECT product_id, MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

UNION

-- If a product has no price change before 2019-08-16, its price is 10
SELECT product_id, 10 AS price
FROM Products
WHERE product_id NOT IN
(
    -- Find the latest change date for each product
    SELECT product_id
    FROM Products
    WHERE change_date <= '2019-08-16'
    
);