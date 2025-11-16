class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0,b=0;
        for(auto x:s){
            if(x=='a')a++;else b++;
        }
        return abs(a-b);
    }
};

