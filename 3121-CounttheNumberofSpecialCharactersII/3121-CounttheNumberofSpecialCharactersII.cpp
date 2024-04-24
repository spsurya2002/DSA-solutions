    int numberOfSpecialChars(string word) {
       map<char,int>m;
       int i=0;
       for(auto x:word){
        if(x>='a'&&x<='z')
        m[x]=i;
"
