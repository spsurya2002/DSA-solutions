            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    if(dp[0][j].first>=1){
                     if(dp[0][j].first==dp[0][j].second)ans++;
                     }
            }
                {dp[i][j].first=dp[i][j].first+dp[i-1][j].first;
                dp[i][j].second=dp[i][j].second+dp[i-1][j].second;
               if(dp[i][j].first>=1){
                   if(dp[i][j].first==dp[i][j].second)ans++;
               }}
            }
        }
            else
[
