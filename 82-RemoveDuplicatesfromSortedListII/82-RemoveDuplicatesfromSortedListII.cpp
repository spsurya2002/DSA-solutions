        }

        ListNode* temp1=new ListNode();
        ListNode* ans=temp1;
        for(auto x:st){
            ListNode* nnd=new ListNode(x);
            temp1->next=nnd;
            temp1=temp1->next;
        }
        return ans->next;
    }
};
            if(x.second==1)st.insert(x.first);
[1,2,3,3,4,4,5]
[1,1,1,2,3]
[1,2,5]
[2,3]
[1,2,5]
[2,3]
[
