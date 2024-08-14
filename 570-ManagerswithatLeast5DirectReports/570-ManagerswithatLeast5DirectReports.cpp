# Write your MySQL query statement below
SELECT name FROM  Employee  JOIN (SELECT managerId as id,COUNT(managerId) as cnt
FROM Employee
GROUP BY managerId
HAVING cnt>=5) as newTable USING(id)
;
{"headers":{"Employee":["id","name","department","managerId"]},"rows":{"Employee":[[101,
"John","A",null],[102,"Dan","A",101],[103,"James","A",101],[104,"Amy","A",101],[105,"Anne",
"A",101],[106,"Ron","B",101]]}}
| name |
| ---- |
| John |
| name |
| ---- |
| John |
[
