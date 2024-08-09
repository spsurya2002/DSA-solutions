# Write your MySQL query statement below
SELECT user_id,COUNT(follower_id)  as followers_count  
FROM Followers
GROUP BY user_id
ORDER BY user_id
;
{"headers":{"Followers":["user_id","follower_id"]},"rows":{"Followers":[[0,1],[1,0],[2,
0],[2,1]]}}
| user_id | followers_count |
| ------- | --------------- |
| 0       | 1               |
| 1       | 1               |
| 2       | 2               |
| user_id | followers_count |
| ------- | --------------- |
| 0       | 1               |
| 1       | 1               |
| 2       | 2               |
[
