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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        if((head->next)==NULL)
            return head;
        ListNode *p1,*t1,*temp;
        p1=head;
        t1=p1->next;
        head=t1;
        temp=t1->next;
        while(temp!=NULL){
            t1->next=p1;
            p1->next=(temp->next!=NULL)?(temp->next):temp;
            p1=temp;
            t1=p1->next;
            temp=(t1!=NULL)?t1->next:NULL;
        }
        if(t1!=NULL){
            t1->next=p1;
            p1->next=NULL;
        }
        return head;
    }
};
