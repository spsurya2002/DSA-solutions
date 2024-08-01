# Write your MySQL query statement below
SELECT * FROM cinema
WHERE id%2!=0 AND description!="boring"   ORDER BY rating DESC;
{"headers":{"cinema":["id","movie","description","rating"]},"rows":{"cinema":[[1,"War","great 3D",
8.9],[2,"Science","fiction",8.5],[3,"irish","boring",6.2],[4,"Ice song","Fantacy",8.6],[5,"House 
card","Interesting",9.1]]}}
| id | movie      | description | rating |
| -- | ---------- | ----------- | ------ |
| 5  | House card | Interesting | 9.1    |
| 1  | War        | great 3D    | 8.9    |
| id | movie      | description | rating |
| -- | ---------- | ----------- | ------ |
| 5  | House card | Interesting | 9.1    |
| 1  | War        | great 3D    | 8.9    |
[
