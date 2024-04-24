    int numberOfSpecialChars(string word) {
      unordered_map<char,int>m;
       int i=0;
       for(auto x:word){
        if(x>='a'&&x<='z')
        m[x]=i;
        else{
            if(m.find(x)==m.end())m[x]=i;
            // if(m[x]==0)m[x]=i;
        }i++;
       }
       int ans=0;
"
