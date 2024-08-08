# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT(subject_id)) as cnt 
FROM Teacher
GROUP BY teacher_id;
{"headers":{"Teacher":["teacher_id","subject_id","dept_id"]},"rows":{"Teacher":[[1,2,3],[1,2,4],
[1,3,3],[2,1,1],[2,2,1],[2,3,1],[2,4,1]]}}
| teacher_id | cnt |
| ---------- | --- |
| 1          | 2   |
| 2          | 4   |
| teacher_id | cnt |
| ---------- | --- |
| 1          | 2   |
| 2          | 4   |
[
