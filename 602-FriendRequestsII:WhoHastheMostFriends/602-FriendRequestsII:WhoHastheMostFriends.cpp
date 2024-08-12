ORDER BY num DESC
LIMIT 1
;
GROUP BY id 
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
