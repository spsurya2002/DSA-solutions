   WHEN id%2=0  THEN id-1
   WHEN id%2=1 AND id+1<=(SELECT MAX(id) FROM Seat) THEN id+1
   ELSE id
   END AS id, student
FROM Seat
ORDER BY id ;
{"headers":{"Seat":["id","student"]},"rows":{"Seat":[[1,"Abbot"],[2,"Doris"],[3,"Emerson"],[4,
"Green"],[5,"Jeames"]]}}
| id | student |
| -- | ------- |
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
| id | student |
| -- | ------- |
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
[
