(SELECT title as results
UNION ALL
LIMIT 1)
ORDER BY COUNT(*) DESC, name
GROUP BY name
USING(user_id)
FROM MovieRating LEFT JOIN Movies
USING(movie_id)
WHERE EXTRACT(YEAR_MONTH FROM MovieRating.created_at)=202002
GROUP BY movie_id
ORDER BY AVG(rating) DESC, title
LIMIT 1)
;
{"headers":{"Movies":["movie_id","title"],"Users":["user_id","name"],"MovieRating":["movie_id",
"user_id","rating","created_at"]},"rows":{"Movies":[[1,"Avengers"],[2,"Frozen 2"],[3,"Joker"]],
"Users":[[1,"Daniel"],[2,"Monica"],[3,"Maria"],[4,"James"]],"MovieRating":[[1,1,3,
"2020-01-12"],[1,2,4,"2020-02-11"],[1,3,2,"2020-02-12"],[1,4,1,"2020-01-01"],[2,1,5,
"2020-02-17"],[2,2,2,"2020-02-01"],[2,3,2,"2020-03-01"],[3,1,3,"2020-02-22"],[3,2,4,
"2020-02-25"]]}}
| results  |
| -------- |
| Daniel   |
| Frozen 2 |
| results  |
| -------- |
| Daniel   |
| Frozen 2 |
[
