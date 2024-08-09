# Write your MySQL query statement below
SELECT MAX(num) as num 
FROM(SELECT num
FROM MyNumbers
GROUP by num
HAVING COUNT(num)=1) as newMYnumber
;
{"headers":{"MyNumbers":["num"]},"rows":{"MyNumbers":[[8],[8],[3],[3],[1],[4],[5],[6]]}}
{"headers":{"MyNumbers":["num"]},"rows":{"MyNumbers":[[8],[8],[7],[7],[3],[3],[3]]}}
| num |
| --- |
| 6   |
| num  |
| ---- |
| null |
| num |
| --- |
| 6   |
| num  |
| ---- |
| null |
[
