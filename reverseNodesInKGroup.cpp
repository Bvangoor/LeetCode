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
            node=node->next;
            len++;
        }
        return len;
    }
    
    bool check(ListNode *node, int k){
        if(length(node)<k)
            return false;
        return true;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==0||k==1)
            return head;
        ListNode *current,*startPtr,*prevPtr,*next,*temp,*prev;
        int count1=1;
        if(check(head,k)){
            current=head;
            count1=1;
            startPtr=head;
            prev=NULL;
            while((count1<=k)&&(current!=NULL)){
                temp=current->next;
                current->next=prev;
                prev=current;
                current=temp;
                count1++;
            }
            head=prev;
            startPtr->next=temp;
            prevPtr=startPtr;
            startPtr=startPtr->next;
        }else{
            return head;
        }
        if(check(current,k)){
            count1=1;
            prev=NULL;
            while((count1<=k)&&(current!=NULL)){
                temp=current->next;
                current->next=prev;
                prev=current;
                current=temp;
                if(count1==k){
                    startPtr->next=temp;
                    prevPtr->next=prev;
                    count1=1;
                    prev=NULL;
                    prevPtr=startPtr;
                    startPtr=startPtr->next;
                    if(!check(current,k))
                        break;
                }else{
                count1++;
                }
            }
        }else{
            return head;
        }
    return head;
    }
};
