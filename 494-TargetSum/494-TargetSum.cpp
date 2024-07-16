    int find(vector<int>& nums,int target,int cur_sum,int i){
public:
class Solution {
        if(i>=nums.size()&&cur_sum==target)return 1;
        if(i>=nums.size()){
            return 0;
        }
        int ans1=find(nums,target,cur_sum+nums[i],i+1);
[
