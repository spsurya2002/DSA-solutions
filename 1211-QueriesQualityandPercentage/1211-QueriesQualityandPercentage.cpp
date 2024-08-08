SELECT query_name, 
FROM Queries
GROUP BY query_name;
ROUND(AVG(rating<3)*100,2) AS poor_query_percentage
ROUND((SUM(rating/position))/COUNT(query_name),2) as quality,
WHERE query_name IS NOT NULL

{"headers":{"Queries":["query_name","result","position","rating"]},"rows":{"Queries":[["Dog","Golden 
Retriever",1,5],["Dog","German Shepherd",2,5],["Dog","Mule",200,1],["Cat","Shirazi",5,2],["Cat",
"Siamese",3,3],["Cat","Sphynx",7,4]]}}
| query_name | quality | poor_query_percentage |
| ---------- | ------- | --------------------- |
| Dog        | 2.5     | 33.33                 |
| Cat        | 0.66    | 33.33                 |
| query_name | quality | poor_query_percentage |
| ---------- | ------- | --------------------- |
| Dog        | 2.5     | 33.33                 |
| Cat        | 0.66    | 33.33                 |
[
