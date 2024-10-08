# Write your MySQL query statement below
SELECT product_name, year ,price 
INNER JOIN Product
FROM sales
USING(product_id);

{"headers":{"Sales":["sale_id","product_id","year","quantity","price"],"Product":["product_id",
"product_name"]},"rows":{"Sales":[[1,100,2008,10,5000],[2,100,2009,12,5000],[7,200,2011,15,9000]],
"Product":[[100,"Nokia"],[200,"Apple"],[300,"Samsung"]]}}
| product_name | year | price |
| ------------ | ---- | ----- |
| Nokia        | 2009 | 5000  |
| Nokia        | 2008 | 5000  |
| Apple        | 2011 | 9000  |
| product_name | year | price |
| ------------ | ---- | ----- |
| Nokia        | 2009 | 5000  |
| Nokia        | 2008 | 5000  |
| Apple        | 2011 | 9000  |
[
