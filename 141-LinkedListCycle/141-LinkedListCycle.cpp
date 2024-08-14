 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=nullptr||fast!=nullptr){
            slow=slow->next;
            fast=fast->next;
            if(slow==nullptr||fast==nullptr)return false;
            if(slow==fast)return true;
        }
    }
        return false;
            if(fast!=nullptr)fast=fast->next;
[3,2,0,-4]
1
[1,2]
0
[1]
-1
[1,2]
-1
true
true
false
false
true
true
false
false
[
