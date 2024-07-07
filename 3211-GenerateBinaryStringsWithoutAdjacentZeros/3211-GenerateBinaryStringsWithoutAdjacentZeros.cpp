            res.push_back(x+'1');
        }
        return res;
    }
public:
    vector<string> validStrings(int n) {
        vector<string> res=  find_subs(n);
        vector<string> ans;
        for(auto x:res){
            if(check_valid(x))ans.push_back(x);
        }return ans;
3
