         return 0;
        }
        if(dp[z][o][i]!=-1)return dp[z][o][i];
        vector<int> v=calc01(strs[i]);
        int zero = v[0];
        int one = v[1];
        if(zero+z<=m&&o+one<=n)
        return dp[z][o][i]=max(find01(strs,m,n,z+zero,o+one,i+1)+1,find01(strs,m,n,z,o,i+1));
        return dp[z][o][i]=find01(strs,m,n,z,o,i+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        fill();
        int ans = find01(strs,m,n,0,0,0);
        return ans;
    }
[
