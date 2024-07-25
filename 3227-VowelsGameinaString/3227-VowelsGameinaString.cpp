    bool doesAliceWin(string s) {
        vector<int>v;
        string vowel = "aeiou";
        for(int i=0;i<s.length();i++){
            if(vowel.find(s[i])!=string::npos)
            v.push_back(i);
"leetcoder"
"bbcd"
"ifld"
1 2 5 7 

0 
true
false
true
true
false
true
"
