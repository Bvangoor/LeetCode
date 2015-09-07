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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prevPtr=NULL, *prev, *temp, *next, *nextPtr;
        int count=2,k=1,diff;
        diff=n-m;
        if (diff==0)
            return head;
        if(m==1)
            prev=head;
        else{
            prevPtr=head;
            prev=head->next;
            while((count<m)&&(prev!=NULL)){
                prevPtr=prevPtr->next;
                prev=prev->next;
                count++;
            }
        }
        nextPtr=prev;
        next=prev->next;
        prev->next=NULL;
        while((k<=diff)&&(next!=NULL)){
            temp=next->next;
            next->next=prev;
            prev=next;
            next=temp;
            k++;
        }
        nextPtr->next=next;
        if(prevPtr!=NULL)
            prevPtr->next=prev;
        if((m==1)){
            head=prev;
        }
        return head;
    }
};
