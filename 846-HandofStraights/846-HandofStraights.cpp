        map<int,int>m;
        for(auto x:hand)m[x]++;
        for(int i=0;i<hand.size();i+=groupSize){
            auto x=*m.begin();
            int y=x.first;
            for(int j=1;j<groupSize;j++){
                 if(m.find(y)!=m.end()){
            m[y]--;if(m[y]==0){m.erase(y);}
                    m[y]--;if(m[y]==0){m.erase(y);}
                 }else return false;
                y=y+1;
            }
[
