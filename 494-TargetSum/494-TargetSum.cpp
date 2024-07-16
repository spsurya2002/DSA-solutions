    
public:
class Solution {
    vector<int> find(vector<int>& nums,int i){
        if(i==nums.size()-1){
            return {-1*nums[i],nums[i]};
        }
        vector<int> res = find(nums,i+1);
        vector<int> myres;
        for(auto x:res){
            myres.push_back(x+nums[i]);
            myres.push_back(x-nums[i]);
        }
        return myres;
[
