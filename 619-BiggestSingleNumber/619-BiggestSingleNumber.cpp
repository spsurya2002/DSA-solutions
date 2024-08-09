SELECT 
    CASE 
        WHEN COUNT(*) = 0 THEN NULL
        ELSE (
            SELECT num
            FROM MyNumbers
            GROUP BY num
            HAVING COUNT(num) = 1
            ORDER BY num DESC
            LIMIT 1
        )
    END AS num
FROM MyNumbers
LIMIT 1;

{"headers":{"MyNumbers":["num"]},"rows":{"MyNumbers":[[8],[8],[3],[3],[1],[4],[5],[6]]}}
{"headers":{"MyNumbers":["num"]},"rows":{"MyNumbers":[[8],[8],[7],[7],[3],[3],[3]]}}
| num |
| --- |
| 6   |
| num  |
| ---- |
| null |
| num |
| --- |
| 6   |
| num  |
| ---- |
| null |
[
