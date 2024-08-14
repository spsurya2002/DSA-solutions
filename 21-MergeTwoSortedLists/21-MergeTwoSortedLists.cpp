                list1=list1->next;
                head=head->next;
            }
        }
        while(list2!=nullptr){
         while(list1!=nullptr){
             head->next=new ListNode(list1->val);
         }
                list1=list1->next;
                head=head->next;
             head->next=new ListNode(list2->val);
                head->next=new ListNode(list1->val);
                
                head=head->next;
            }else{
                list2=list2->next;
                head->next=new ListNode(list2->val);
[1,2,4]
[1,3,4]
[]
[]
[]
[0]
1 1
1 3
2 3
4 3
4 4



[1,1,2,3,4,4]
[]
[0]
[1,1,2,3,4,4]
[]
[0]
[
