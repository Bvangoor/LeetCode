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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    ListNode *temp,*newHead;
    int carry=0,value1;
    temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    value1=carry + l1->val + l2->val;
    if(value1>=10){
        carry=1;
        value1=value1-10;
    }else{
        carry=0;
    }
    temp->val=value1;
    temp->next=NULL;
    newHead=temp;
    l1=l1->next;
    l2=l2->next;
    while((l1!=NULL)&&(l2!=NULL)){
        ListNode *temp1;
        temp1=(struct ListNode*)malloc(sizeof(struct ListNode));
        value1=carry + l1->val + l2->val;
        if(value1>=10){
            carry=1;
            value1=value1-10;
        }else{
            carry=0;
        }
        temp1->val=value1;
        temp1->next=NULL;
        temp->next=temp1;
        temp=temp->next;
        l1=l1->next;
        l2=l2->next;
    }
    if((l1!=NULL)&&(l2==NULL)){
        if(carry==0){
            temp->next=l1;
        }else{
            while(l1!=NULL){
                ListNode *temp1;
                temp1=(struct ListNode*)malloc(sizeof(struct ListNode));
                value1=carry + l1->val;
                if(value1>=10){
                    carry=1;
                    value1=value1-10;
                }else{
                    carry=0;
                }
                temp1->val=value1;
                temp1->next=NULL;
                temp->next=temp1;
                temp=temp->next;
                l1=l1->next;
            }
        }
    }else if((l2!=NULL)&&(l1==NULL)){
        if(carry==0){
            temp->next=l2;
        }else{
            while(l2!=NULL){
                ListNode *temp1;
                temp1=(struct ListNode*)malloc(sizeof(struct ListNode));
                value1=carry + l2->val;
                if(value1>=10){
                    carry=1;
                    value1=value1-10;
                }else{
                    carry=0;
                }
                temp1->val=value1;
                temp1->next=NULL;
                temp->next=temp1;
                temp=temp->next;
                l2=l2->next;
            }
        }
    }
    if(carry==1){
        ListNode *temp1;
        temp1=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp1->val=1;
        temp1->next=NULL;
        temp->next=temp1;
    }
    return newHead;
}
};
