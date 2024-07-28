# Write your MySQL query statement below
SELECT  customer_id,COUNT(customer_id) as count_no_trans FROM
Visits LEFT JOIN Transactions
on Visits.visit_id=Transactions.visit_id
WHERE Visits.visit_id NOT IN (
SELECT visit_id
{"headers":{"Visits":["visit_id","customer_id"],"Transactions":["transaction_id","visit_id",
"amount"]},"rows":{"Visits":[[1,23],[2,9],[4,30],[5,54],[6,96],[7,54],[8,54]],"Transactions":[[2,5,
310],[3,5,300],[9,5,200],[12,1,910],[13,2,970]]}}
| customer_id | count_no_trans |
| ----------- | -------------- |
| 30          | 1              |
| 96          | 1              |
| 54          | 2              |
| customer_id | count_no_trans |
| ----------- | -------------- |
| 30          | 1              |
| 96          | 1              |
| 54          | 2              |
[
