       map<char,deque<int>>m;
       int i=0;
       for(auto x:word){
        m[x].push_back(i);
        i++;
       }
       int ans=0;
       for(auto x:m){
        if(m.find(c)!=m.end()){
            if(m[c].back()<x.second.front())ans++;
public:
    int numberOfSpecialChars(string word) {
        char c=x.first+32;
"
