                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                // Link prev to the node after the duplicates
                prev->next = current->next;
            } else {
                // Skip all duplicates
            if (current->next && current->val == current->next->val) {
        while (current) {
            // If current has a duplicate, skip all nodes with the same value
        
        ListNode* current = head;
        ListNode* prev = dummy;  // Points to the last node before the duplicate sequence
        ListNode* dummy = new ListNode(0, head);
        // Create a dummy node to handle edge cases (like head being part of duplicates)
    ListNode* deleteDuplicates(ListNode* head) {
public:
class Solution {
[1,2,3,3,4,4,5]
[1,1,1,2,3]
[1,2,5]
[2,3]
[1,2,5]
[2,3]
[
