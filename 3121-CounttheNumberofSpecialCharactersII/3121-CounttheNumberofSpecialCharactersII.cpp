        if(x>='a'&&x<='z')
        m[x]=i;
        else{
            if(m[x]==0)m[x]=i;
        }i++;
       }
       int ans=0;
       for(auto x:m){
       char c=x.first+32;
       cout<<x.first<<" "<<x.second<<endl;
        if(m.find(c)!=m.end()){
            if(m[c]<x.second)ans++;
        }
       for(auto x:word){
       int i=0;
"
