            dp[m-1][i]=freq[m-1][i];
        }
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<10;i++){
                int mi=INT_MAX;
                for(int k=0;k<10;k++){
                    if(i!=k)mi=min(mi,dp[j+1][k]);
[
