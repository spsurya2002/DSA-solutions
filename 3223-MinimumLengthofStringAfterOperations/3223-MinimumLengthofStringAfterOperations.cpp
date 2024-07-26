class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>m;
        for(auto x:s)m[x]++;
        int ans=0;
        for(auto x:m){
            ans++;
        }
        return ans;
    }
            if(!(x.second%2))ans++;
};
"abaacbcbb"
"aa"
5
2
5
2
"
