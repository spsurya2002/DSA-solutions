        int pos=(i+k)%v.size();
        v.erase(v.begin()+pos);
        josh(pos,v,k);
    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        int i=1;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        k--;
        josh(0,v,k);
        return ans;
    }
};
5
2
6
5
3
1
3
1
5
