                if(s[i]-elem<dif){
                    dif=s[i]-elem;
                    pos2=i;
                }
            }
        }
        swap(s[pos],s[pos2]);
        sort(s.begin()+pos+1,s.end());
        string max=to_string(INT_MAX);
        cout<<s<<endl<<max<<endl;
        if(s.length()==max.length()){
            if(s>max)return -1;
        }

321
21
4321452
3215
2147483486


4321524
2147483647

3251
2147483647

2147483648
2147483647

-1
-1
4321524
3251
-1
-1
-1
4321524
3251
-1
3
