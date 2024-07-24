class Solution {
public:
    int find(vector<int>& nums,int target,int cur_sum,int i){
        if(i>=nums.size()&&cur_sum==target)return 1;
        if(i>=nums.size()){
            return 0;
        }
        int ans1=find(nums,target,cur_sum+nums[i],i+1);
        int ans2=find(nums,target,cur_sum-nums[i],i+1);
        return ans1+ans2;
        

    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int ans= find(nums,target,0,0);
        return ans;
    }
};
[1,1,1,1,1]
