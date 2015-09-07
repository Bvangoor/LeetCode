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

    bool check(ListNode *f, ListNode *s, ListNode *t){
        if(f->val == s->val)
            return false;
        if(s->val == t->val)
            return false;
        return true;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode *current, *prev;
        current=head;
        if(current->next == NULL)
            return head;
        if(((current->next)!=NULL)&&((current->val)!=(current->next->val))){
            prev=head;
            current=current->next;
        }else{
            ListNode *first,*second,*third;
            first=head;
            second=first->next;
            third=second->next;
            if(third==NULL)
                return NULL;
            while(!check(first,second,third)){
                first=first->next;
                second=second->next;
                third=third->next;
                if(third==NULL){
                    if((first->val)==(second->val))
                        return NULL;
                    else
                        break;
                }
            }
            head=second;
            prev=head;
            current=prev->next;
        }
        while((current!=NULL)&&((current->next)!=NULL)){
            if(((current->next)!=NULL)&&((current->val)!=(current->next->val))){
                prev=prev->next;
                current=current->next;
            }else{
                while(((current->next)!=NULL)&&((current->val)==(current->next->val))){
                    current=current->next;
                }
                current=current->next;
                prev->next=current;
            }
        }
        return head;
        }
};
