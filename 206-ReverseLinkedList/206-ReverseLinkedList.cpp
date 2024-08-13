 * };
 */
class Solution {
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev=NULL;
       ListNode* nxt=NULL;
       ListNode* curr = head;
       while(curr!=nullptr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
       }
       return prev;
    }
};

// class Solution {
[1,2,3,4,5]
[1,2]
[]
[5,4,3,2,1]
[2,1]
[]
[5,4,3,2,1]
[2,1]
[]
[
