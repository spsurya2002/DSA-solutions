        }
        int s4=0;
        b1=true;b2=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1&&b1==true){s4++;b2=true;b1=false;}
            if(nums[i]%2==0&&b2==true){s4++;b2=false;b1=true;;}
        }
        return max({s1,s2,s3,s4});
    }
};
[
