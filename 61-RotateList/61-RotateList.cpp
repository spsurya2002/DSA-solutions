    int len(ListNode* head){
        int l=0;
        while(head){
            l++;
            head=head->next;
        }return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        if(k==0)return head;
        int l = len(head);
        k=k%l;
        if(k==0)return head;
        k=l-k;

        ListNode* fh = head;
        ListNode* ft = fh;
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
