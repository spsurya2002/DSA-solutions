ORDER BY num DESC
LIMIT 1
GROUP BY id 
    GROUP BY accepter_id) as new_table
    UNION ALL
    SELECT accepter_id as id, COUNT(accepter_id) as cnt
    FROM RequestAccepted
    GROUP BY requester_id
    FROM RequestAccepted
FROM (
SELECT id,SUM(cnt) as num
# Write your MySQL query statement below
    SELECT requester_id as id, COUNT(requester_id) as cnt
;
{"headers":{"RequestAccepted":["requester_id","accepter_id","accept_date"]},"rows":
{"RequestAccepted":[[1,2,"2016/06/03"],[1,3,"2016/06/08"],[2,3,"2016/06/08"],[3,4,"2016/06/
09"]]}}
| id | num |
| -- | --- |
| 3  | 3   |
| id | num |
| -- | --- |
| 3  | 3   |
[
