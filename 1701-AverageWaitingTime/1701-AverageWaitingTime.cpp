class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double finishTime=customers[0][0]+customers[0][1];
        double sumTime=finishTime-customers[0][0];
[
