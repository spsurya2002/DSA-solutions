       while(temp!=nullptr){
        v.push_back(temp->val);
        temp=temp->next;
       }
       int i=0,j=v.size()-1;
       while(i<j){
        head->val=v[i];i++;head=head->next;
        if(i<j){
        head->val=v[j];
        head=head->next;
        j--;}
[1,2,3,4]
[1,2,3,4,5]
[1,4,2,3]
[1,5,2,4,3]
[1,4,2,3]
[1,5,2,4,3]
[
