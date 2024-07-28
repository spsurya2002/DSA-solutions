# Write your MySQL query statement below
SELECT product_id FROM Products
WHERE low_fats='Y' AND recyclable='Y';
{"headers":{"Products":["product_id","low_fats","recyclable"]},"rows":{"Products":[[0,"Y","N"],[1,
"Y","Y"],[2,"N","Y"],[3,"Y","Y"],[4,"N","N"]]}}
| product_id |
| ---------- |
| 1          |
| 3          |
| product_id |
| ---------- |
| 1          |
| 3          |
[
C
