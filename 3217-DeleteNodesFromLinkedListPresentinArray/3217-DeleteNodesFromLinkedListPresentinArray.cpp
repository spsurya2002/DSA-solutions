       ListNode*  ans = nullptr;
       ListNode*  last = nullptr;
       while(temp!=NULL){
        int data=temp->val;
        if(!(binary_search(nums.begin(),nums.end(),data))){
           ListNode* newNode = new ListNode(data);
           if(ans==nullptr){ans=newNode;last=newNode;}
           else{
            last->next = newNode;
            last = newNode;
           }
         }temp = temp->next;
       } 
       return ans;
    }
    
};
[
