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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *current;
        while(head!=NULL){
            if(head->val==val){
                head=head->next;
            }else{
                break;
            }
        }
        if(head==NULL)
            return NULL;
        prev=head;
        current=head->next;
        while(current!=NULL){
            if(current->val==val){
                current=current->next;
                prev->next=current;
            }else{
                prev=prev->next;
                current=current->next;
            }
        }
        return head;
    }
};
