public:
class Solution {
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101, head);
        ListNode* prev = dummy;  
        ListNode* current = head;
        
        while (current) {
            if (current->next && current->val == current->next->val) {
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } else {
                prev = prev->next;
            }
[1,2,3,3,4,4,5]
[1,1,1,2,3]
[-101,1,2,3,3,4,4,5]
[-101,1,1,1,2,3]
[1,2,5]
[2,3]
[
