class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
         int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        unsigned int ans=0;
        for(int i=0;i<n;i++){
            unsigned sum=0,cnt=1;
            for(int j=i;j<n;j++){
                sum+=cnt*satisfaction[j];
                cnt++;
            }ans=max(ans,sum);
        }return ans;

    }
};
[-1,-8,0,5,-7]
