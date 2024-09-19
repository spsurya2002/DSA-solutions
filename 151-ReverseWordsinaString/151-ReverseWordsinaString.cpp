    string reverseWords(string s) {
        vector<string>v;
        for(int i=0;i<s.length();){
            while(i<s.length()&&s[i]==' '){i++;}
            string t="";
            while(i<s.length()&&s[i]!=' '){
                t+=s[i];i++;
            }
"the sky is blue"
"  hello world  "
"a good   example"
"  Bob    Loves  Alice   "
"EPY2giL"
4
the 3
sky 3
is 2
blue 4

2
hello 5
world 5

3
a 1
good 4
example 7

3
Bob 3
Loves 5
Alice 5

1
EPY2giL 7

"blue is sky the"
"world hello"
"example good a"
"Alice Loves Bob"
"EPY2giL"
"blue is sky the"
"world hello"
"example good a"
"Alice Loves Bob"
"EPY2giL"
"
