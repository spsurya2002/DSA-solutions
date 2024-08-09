# Write your MySQL query statement below
SELECT class FROM  Courses
GROUP BY class
HAVING COUNT(student)>=5;
{"headers":{"Courses":["student","class"]},"rows":{"Courses":[["A","Math"],["B",
"English"],["C","Math"],["D","Biology"],["E","Math"],["F","Computer"],["G","Math"],["H",
"Math"],["I","Math"]]}}
| class |
| ----- |
| Math  |
| class |
| ----- |
| Math  |
[
