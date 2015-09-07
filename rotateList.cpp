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
    int length(ListNode *node){
        int len=0;
        if(node==NULL)
            return len;
        while(node!=NULL){
            len++;
            node=node->next;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        int len,rot,str,count=2;
        len=length(head);
        rot=k%len;
        if(rot==0)
            return head;
        str=len-rot+1;
        ListNode *prev_head,*prev,*temp;
        prev_head=head;
        prev=head;
        temp=head->next;
        while((temp!=NULL)&&(count<str)){
            temp=temp->next;
            prev=prev->next;
            count++;
        }
        head=temp;
        prev->next=NULL;
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=prev_head;
        return head;
    }
};
