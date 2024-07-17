       }
       int ans1= find(words,letters,score,mp,i+1);
       int ans2=0;
       if(b){
       for(auto x:words[i])mp[x]--;
       ans2=find(words,letters,score,mp,i+1)+sc;
       }
       return max(ans1,ans2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(auto x:letters)mp[x]++;
        sc+=score[x-'a'];
        if(tmp[x]>mp[x]){b=false;}
       for(auto x:words[i]){
       for(auto x:words[i])tmp[x]++;
       unordered_map<char,int>tmp;
       int sc=0;
       bool b = true;
       if(i>=words.size())return 0;
    int find(vector<string>& words, vector<char>& letters, vector<int>& score,unordered_map<char,int>mp,int i){
public:
class Solution {
["dog","cat","dad","good"]
