/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if((head==NULL)||(head->next==NULL))
            return false;
        slow=fast=head;
        slow=head->next;
        fast=head->next->next;
        while((slow!=NULL)&&(fast!=NULL)){
            if(slow==fast)
                return true;
            else{
                slow=slow->next;
                fast=fast->next;
                if(fast==NULL)
                    return false;
                fast=fast->next;
            }
        }
        return false;
    }
};
