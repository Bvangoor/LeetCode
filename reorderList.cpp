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
    void reorderList(ListNode* head) {
        if(head==NULL)
            return ;
        if((head->next)==NULL)
            return ;
        ListNode *start, *slow, *fast,*middle;
        start=slow=fast=head;
        while((fast!=NULL)&&((fast->next)!=NULL)){
            slow=slow->next;
            fast=fast->next->next;
        }
        middle=slow;
        if((middle->next)==NULL)
            return;
        ListNode *next,*temp,*prev,*last;
        prev=middle;
        next=middle->next;
        middle->next=NULL;
        while(next!=NULL){
            temp=next->next;
            next->next=prev;
            prev=next;
            next=temp;
        }
        last=prev;
        while((last!=middle)&&(start!=last)){
            ListNode *temp1,*temp2;
            temp1=start->next;
            temp2=last->next;
            start->next=last;
            last->next=temp1;
            start=temp1;
            last=temp2;
        }
    }
};
