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
};
