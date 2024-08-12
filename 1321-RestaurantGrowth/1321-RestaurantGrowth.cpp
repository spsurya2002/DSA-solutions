    FROM customer
    WINDOW w AS ( 
            ORDER BY visited_on
            RANGE BETWEEN interval 6 day PRECEDING and current row
    )
Limit 6, 999
SELECT DISTINCT visited_on,
        SUM(amount) OVER w AS amount,
        ROUND((SUM(amount) OVER w)/7, 2) AS average_amount
{"headers":{"Customer":["customer_id","name","visited_on","amount"]},"rows":{"Customer":[[1,"Jhon","2019-01-01",100],[2,
"Daniel","2019-01-02",110],[3,"Jade","2019-01-03",120],[4,"Khaled","2019-01-04",130],[5,"Winston","2019-01-05",110],[6,
"Elvis","2019-01-06",140],[7,"Anna","2019-01-07",150],[8,"Maria","2019-01-08",80],[9,"Jaze","2019-01-09",110],[1,"Jhon",
"2019-01-10",130],[3,"Jade","2019-01-10",150]]}}
| visited_on | total_amount | average_amount |
| ---------- | ------------ | -------------- |
| 2019-01-07 | 150          | 150            |
| 2019-01-08 | 80           | 80             |
| 2019-01-09 | 110          | 110            |
| 2019-01-10 | 280          | 140            |
| visited_on | amount | average_amount |
| ---------- | ------ | -------------- |
| 2019-01-07 | 860    | 122.86         |
| 2019-01-08 | 840    | 120            |
| 2019-01-09 | 840    | 120            |
| 2019-01-10 | 1000   | 142.86         |
[
