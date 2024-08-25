        while(mid&&fast){
            mid = mid->next;
            fast=fast->next;
            if(!fast)break;
            fast=fast->next;
        }
       ListNode* rmid= reverseRecursive(mid);
       display(rmid);
        while(rmid!=nullptr){
            if(temp->val!=rmid->val)return false;
            rmid=rmid->next;
            temp=temp->next;
        }
        return true;

    }
};
[1,2,2,1]
[1,2]
[1,3,2,4,3,2,1]
true
false
false
true
false
false
[
