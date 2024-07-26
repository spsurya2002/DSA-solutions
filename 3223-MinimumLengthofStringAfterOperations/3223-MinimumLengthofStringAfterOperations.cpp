class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>m;
        for(auto x:s)m[x]++;
        int ans=0;
        for(auto x:m){
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second>2&&x.second%2==0)ans+=2;
            else if(x.second>2)ans+=1;
            else ans+=x.second;
        }
"abaacbcbb"
"aa"
c 2
b 4
a 3

a 2

5
2
5
2
"
