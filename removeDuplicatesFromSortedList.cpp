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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp,*next;
        if(head==NULL)
            return head;
        temp=head;
        next=temp->next;
        while(next!=NULL){
            if(temp->val==next->val){
                next=next->next;
                if(next==NULL)
                    temp->next=next;
            }else{
                temp->next=next;
                temp=next;
                next=next->next;
            }
        }
        return head;
    }
};
