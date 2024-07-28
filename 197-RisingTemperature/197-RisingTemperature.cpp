-- Select the IDs from Weather where the temperature is higher than the previous day
SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1
AND w1.temperature > w2.temperature;
{"headers":{"Weather":["id","recordDate","temperature"]},"rows":{"Weather":[[1,"2015-01-01",10],[2,
"2015-01-02",25],[3,"2015-01-03",20],[4,"2015-01-04",30]]}}
| id |
| -- |
| 2  |
| 4  |
| 2  |
| Id |
| -- |
| 2  |
| 4  |
[
