       while(temp!=nullptr){
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        v.push_back(temp->val);
       }
        temp=temp->next;
       vector<int>v;
       ListNode* temp=head;
       int i=0,j=v.size()-1;
       while(i<=j){
        head->val=v[i];i++;head=head->next;
        j--;}
        head->val=v[j];
        if(i<j){
        head=head->next;
[1,2,3,4]
[1,2,3,4,5]
[1,4,2,3]
[1,5,2,4,3]
[1,4,2,3]
[1,5,2,4,3]
[
