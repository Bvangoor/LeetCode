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
    
    ListNode *returnIntersection(ListNode *node1, ListNode *node2){
        while((node1!=NULL)&&(node2!=NULL)){
            if(node1->val==node2->val)
                return node1;
            node1=node1->next;
            node2=node2->next;
        }
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1,len2,diff,temp=0;
        len1=length(headA);
        len2=length(headB);
        diff=abs(len1-len2);
        ListNode *t1,*t2;
        if(len1==len2){
            t1=headA;
            t2=headB;
        }
        if(len1<len2){
            t1=headA;
            t2=headB;
        }    
        if(len1>len2){
            t2=headA;
            t1=headB;
            
        }
        while(temp<diff){
                t2=t2->next;
                temp++;
        }
        return returnIntersection(t1,t2);
    }
};
