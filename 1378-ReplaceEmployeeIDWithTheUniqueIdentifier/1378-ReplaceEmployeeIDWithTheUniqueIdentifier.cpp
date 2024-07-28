# Write your MySQL query statement below
SELECT unique_id, name FROM Employees as E
LEFT JOIN EmployeeUNI as EU
ON E.id=EU.id;
{"headers":{"Employees":["id","name"],"EmployeeUNI":["id","unique_id"]},"rows":{"Employees":[[1,
"Alice"],[7,"Bob"],[11,"Meir"],[90,"Winston"],[3,"Jonathan"]],"EmployeeUNI":[[3,1],[11,2],[90,3]]}}
| unique_id | name     |
| --------- | -------- |
| null      | Alice    |
| null      | Bob      |
| 2         | Meir     |
| 3         | Winston  |
| 1         | Jonathan |
| unique_id | name     |
| --------- | -------- |
| null      | Alice    |
| null      | Bob      |
| 2         | Meir     |
| 3         | Winston  |
| 1         | Jonathan |
[
