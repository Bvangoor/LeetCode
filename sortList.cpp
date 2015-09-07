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

void splitList(ListNode *temp, ListNode **a, ListNode **b){
    ListNode *slow,*fast;
    if(temp==NULL || temp->next==NULL){
        *a=temp;
        *b=NULL;
        return;
    }else{
        slow=temp;
        fast=temp->next->next;
        while((slow!=NULL)&&(fast!=NULL)){
            slow=slow->next;
            fast=fast->next;
            if(fast==NULL){
                *a=temp;
                *b=slow->next;
                slow->next=NULL;
                return;
            }else{
                fast=fast->next;
            }
        }
        *a=temp;
        *b=slow->next;
        slow->next=NULL;
        return;
    }
    return;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if((l1==NULL)&&(l2==NULL))
            return l1;
        if((l1!=NULL)&&(l2==NULL))
            return l1;
        if((l1==NULL)&&(l2!=NULL))
            return l2;    
        ListNode *t1,*temp,*t2;
        t1=l1;
        t2=l2;
        while((t1!=NULL)&&(t2!=NULL)){
            if(t1->val<=t2->val){
                while(((t1->next)!=NULL)&&(t1->next->val<=t2->val)){
                    t1=t1->next;
                }
                temp=t1->next;
                t1->next=t2;
                t1=temp;
            }else{
                while(((t2->next)!=NULL)&&(t2->next->val<=t1->val)){
                    t2=t2->next;
                }
                temp=t2->next;
                t2->next=t1;
                t2=temp;
            }
        }
        return (l1->val<=l2->val)?l1:l2;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *temp1,*t1,*t2;
        temp1=head;
        splitList(temp1,&t1,&t2);
        t1=sortList(t1);
        t2=sortList(t2);
        head=mergeTwoLists(t1,t2);
        return head;
    }
};
