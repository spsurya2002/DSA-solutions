        
        while (current) {
            if (current->next && current->val == current->next->val) {
        ListNode* current = head;
        ListNode* prev = dummy;  
        ListNode* dummy = new ListNode(0, head);
    ListNode* deleteDuplicates(ListNode* head) {
public:
class Solution {
            }
            current = current->next;
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } else {
                prev = prev->next;
        }
        
[1,2,3,3,4,4,5]
[1,1,1,2,3]
[0,1,2,3,3,4,4,5]
[0,1,1,1,2,3]
[1,2,5]
[2,3]
[
