class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double finishTime=customers[0][0]+customers[0][1];
        double sumTime=finishTime-customers[0][0];
        for(int i=1;i<customers.size();i++){
            if(finishTime<customers[i][0])finishTime=customers[i][0];
            finishTime+=customers[i][1];
            sumTime+=(finishTime-customers[i][0]);
        }
        return ans;
    }
        double ans =  sumTime/(customers.size());
};
[
