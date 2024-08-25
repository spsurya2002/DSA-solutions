            ft=ft->next;
        }
        ListNode* sh = ft->next;
        ListNode* st=sh;
        
        c=0;
        while(c<l-k-1){
            c++;
            st=st->next;
        }
        st->next=fh;
        ft->next=nullptr;
        return sh;
            c++;
        while(c<k-1){
        int c=0;

        ListNode* ft = fh;
        ListNode* fh = head;
[1,2,3,4,5]
2
[0,1,2]
4
[]
0
[1]
1
[1,2]
1
[1,2,3,4,5,6,7,8,9]
3
[1,2]
2
1 2 3 4 5 
3 4 5 
4 5 
5 

0 1 2 
1 2 
2 
2 



2 

1 2 3 4 5 6 7 8 9 
6 7 8 9 
7 8 9 
9 


[4,5,1,2,3]
[2,0,1]
[]
[1]
[2,1]
[7,8,9,1,2,3,4,5,6]
[1,2]
[4,5,1,2,3]
[2,0,1]
[]
[1]
[2,1]
[7,8,9,1,2,3,4,5,6]
[1,2]
[
